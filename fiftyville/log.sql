-- Keep a log of any SQL queries you execute as you solve the mystery.

--Getting some insight into the data and finding crime scene report
.schema

.tables

.schema crime_scene_reports

SELECT COUNT(*) FROM crime_scene_reports;

SELECT * FROM crime_scene_reports LIMIT 15;

SELECT * FROM crime_scene_reports
    WHERE year = 2023
        AND month = 7
        AND day = 28;

--Theft has an ID of 295 from the crime_scene_reports table.
SELECT * FROM crime_scene_reports
    WHERE id = 295;
/*
10:15 am Humphrey Street bakery.
There was conducted 3 interviews.
Can i find those?
*/

.tables

SELECT * FROM interviews LIMIT 15;

SELECT * FROM interviews
    WHERE year = 2023
        AND month = 7
        AND day = 28;

/*
We can use interview id = 161, 162, 163

Clues:
Car drive away from bakery parking lot within 10 min of the theft. Maybe security footage?
Do i have a time from crimescene report?

Eugene recognize the person. Bakery is called EMM's. Theif was withdrawing money from ATM at Leggett Street
before theft.

The theif called someone. Lasted < 1 min. Take earlies flight out of fiftyville. Asked person on phone to
purchase flight tickets.
*/

--Checking crime scene rapport for time

SELECT * FROM crime_scene_reports
    WHERE id = 295;

-- No timestamp.

.tables

--Should follow up on atm_transactions and phone_calls tables first. Im thinking atm first for timeframe.

SELECT * FROM atm_transactions LIMIT 5;

SELECT * FROM atm_transactions
    WHERE atm_location = 'Humphrey Lane'
        AND year = 2023
        AND month = 7
        AND day = 28
        AND transaction_type = 'withdraw';

-- To many entries. No timeframe. Need amount or account
-- Checking phone_calls

SELECT * FROM phone_calls LIMIT 5;

SELECT * FROM phone_calls
    WHERE duration < 60
        AND day = 28
        AND month = 7
        AND year = 2023;

--Also alot of enries. Can really find any good info from this.

.tables

-- Maybe something in people?

SELECT * FROM people LIMIT 5;

--I guess i can crosscheck phone_number for people with receiver from phone_calls?

SELECT * FROM phone_calls
    JOIN people ON receiver = phone_number
        AND year = 2023
        AND month = 7
        AND day = 28
        AND phone_calls.id IN (221, 224, 233, 251, 254, 255, 261, 279, 281)
        AND duration < 60;

-- Dont really know what I am looking for in that table.
--Going to do some backtracking..

--Can we assume that the person on the other side of the phone call also went on a flight?
--If so we could sort on caller, reciver, passport, flights, passangers?

--I want to check bakery_security_logs

--And also bank account i guess? To match with withdraw from ATM?

SELECT * FROM bakery_security_logs LIMIT 5;

--We have car license_plate in that table.

/*
    Known info:
    ID of 295 from the crime_scene_reports table
    Theft happened: 10:15 am Humphrey Street bakery.
    Car drive away from bakery parking lot within 10 min of the theft.
    Theif was withdrawing money from ATM at Leggett Street before theft.
    The theif called someone. Lasted < 1 min.
    Take earlies flight out of fiftyville.
    Asked person on phone topurchase flight tickets.
*/

SELECT license_plate FROM bakery_security_logs
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute IN (15,16,17,18,19,20,21,22,23,24,25,26);

-- Now we know the license_plate is one of 8.

-- We can find the phone no. of license plates from people.

SELECT * FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
        WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
            AND year = 2023
            AND month = 7
            AND day = 28
            AND HOUR = 10
            AND minute IN (16,17,18,19,20,21,22,23,24,25);

-- This is good. I can add on to this passport number or maybe caller, if he used his on phone..

--CALLER = phone_calls.id = 221, 224, 233, 251, 254, 255, 261, 279, 281

SELECT * FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
    JOIN phone_calls ON people.phone_number = phone_calls.caller
        WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
            AND bakery_security_logs.year = 2023
            AND bakery_security_logs.month = 7
            AND bakery_security_logs.day = 28
            AND bakery_security_logs.hour = 10
            AND bakery_security_logs.minute IN (16,17,18,19,20,21,22,23,24,25)
            AND phone_calls.id IN (221, 224, 233, 251, 254, 255, 261, 279, 281);

--I should get passport number to join or reciver to join.  Checked reciver in code above \n
-- The list is longer for recivers and all ppl i this query is in reciver also.

SELECT * FROM flights
    WHERE year = 2023
    AND month = 7
    AND day = 28
    ORDER BY hour ASC;

-- First flight out after 10 is 12:51, but is it from the right airport?

SELECT * FROM airports LIMIT 100;

--FIftyville regional airport id = 8

SELECT * FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
        WHERE flights.year = 2023
            AND flights.month = 7
            AND flights.day = 28
            AND flights.origin_airport_id = 8
                ORDER BY hour ASC;

--Looks like it has to be the first flight after 10:15
--That is flight flights.id = 6

SELECT * FROM flights
    JOIN airports ON flights.origin_airport_id = airports.id
        WHERE flights.year = 2023
            AND flights.month = 7
            AND flights.day = 28
            AND flights.origin_airport_id = 8
            AND flights.id = 6
                ORDER BY hour ASC;

--Who's on this flight? Where does this flight go?
-- Still also need to find acomplise. Can do that with phone records after possibly?

SELECT * FROM passengers
    WHERE flight_id = 6;

-- Using earlier code to find passport number

SELECT passport_number FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
    JOIN phone_calls ON people.phone_number = phone_calls.caller
        WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
            AND bakery_security_logs.year = 2023
            AND bakery_security_logs.month = 7
            AND bakery_security_logs.day = 28
            AND bakery_security_logs.hour = 10
            AND bakery_security_logs.minute IN (16,17,18,19,20,21,22,23,24,25)
            AND phone_calls.id IN (221, 224, 233, 251, 254, 255, 261, 279, 281);
/*
Passport numbers i want to see if is in flight id 6 =
'1695452385', '8294398571', '5773159633', '8294398571', '3592750733'
*/

SELECT * FROM passengers
    WHERE passengers.flight_id = 6
    AND passport_number IN (1695452385, 8294398571, 5773159633, 8294398571, 3592750733);

-- No one here...

-- I will lower the number of arguments.

SELECT * FROM people
    WHERE passport_number IN ('1695452385', '8294398571', '5773159633', '8294398571', '3592750733')
    AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

/*
people.person_id = '398010', '514354', '560886', '686048'
*/

SELECT * FROM atm_transactions LIMIT 15;
SELECT * FROM bank_accounts LIMIT 15;

SELECT * FROM atm_transactions
    JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
        WHERE transaction_type = 'withdraw'
        AND year = 2023
        AND month = 7
        AND day = 28
        AND atm_location = 'Humphrey Lane'
        AND person_id IN ('398010', '514354', '560886', '686048');

--0, none of the cars registerd at the bakery sec logs at 28/07/23 between 10:16 and 10:25 and passport that was present on flight id = 6

-- It might not be flight 6?

SELECT passport_number FROM passengers
    WHERE flight_id = 35;

--Flight 35 passport_number '1682575122', '8284363264', '6627121233', '6632213958', '1801324150', '9143726159', '4377966420', '7021171868'

SELECT * FROM people
    WHERE passport_number IN ('1682575122', '8284363264', '6627121233', '6632213958', '1801324150', '9143726159', '4377966420', '7021171868')
    AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

--No hits again

--These are the exits for the parking lot in the 10 min span after the Theft (license_plate):
-- 5P2BI95 94KL13X 6P58WS2 4328GD8 G412CB7 L93JTIZ 322W7JE 0NTHK55
--Mathc these to people?

SELECT * FROM people
    WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

--Passport number '2963008352', '7526138472', '7049073643', '1695452385', '8496433585', '3592750733', '8294398571', '5773159633'

SELECT * FROM passengers
    WHERE passport_number IN ('2963008352', '7526138472', '7049073643', '1695452385', '8496433585', '3592750733', '8294398571', '5773159633');

--Now, see if the flights are leaving from fiftyville on the right day, and choose earliest flight after 10:15?
--Flight id: '2', '11', '18', '20', '24', '26', '6', '39', '48', '54'

SELECT * FROM flights
    WHERE id IN (2, 11, 18, 20, 24, 26, 6, 39, 48, 54)
    AND origin_airport_id = 8;

-- There is only one flight out from fiftyville on the exact date. Still flight ID 6.

--So lets compare the passports we have to the ones on the flight again?

SELECT * from flights
    JOIN passengers ON flights.id = passengers.flight_id
    WHERE passport_number IN (2963008352, 7526138472, 7049073643, 1695452385, 8496433585, 3592750733, 8294398571, 5773159633)
    AND origin_airport_id = 8;

-- Is the first flight the day after ?? There is no evidence it is on the same day.
-- That would be flight 36

SELECT * from flights
    JOIN passengers ON flights.id = passengers.flight_id
        WHERE passport_number IN (2963008352, 7526138472, 7049073643, 1695452385, 8496433585, 3592750733, 8294398571, 5773159633)
        AND flights.id = 36;

--destination_airport_id = 4
--passport_number = 1695452385, 5773159633, 8294398571, 8496433585

--Lets get the airport done.
SELECT * FROM airports
    WHERE id = 4;

/*

******ANSWER********

The city the thief ESCAPED TO: LaGuardia Airport

*/

--Lets get names for the four passport numbers.

SELECT * FROM people
    WHERE passport_number IN (1695452385, 5773159633, 8294398571, 8496433585);

--And now we can compare with the license_plate from sec_logs.

--'5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55'

SELECT * FROM people
    WHERE passport_number IN (1695452385, 5773159633, 8294398571, 8496433585)
    AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

--Still 4 ppl.


SELECT name, phone_number, caller, receiver, duration FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
    JOIN phone_calls ON people.phone_number = phone_calls.caller
        WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
        AND people.passport_number IN (1695452385, 5773159633, 8294398571, 8496433585)
                AND bakery_security_logs.year = 2023
                AND bakery_security_logs.month = 7
                AND bakery_security_logs.day = 28
                AND bakery_security_logs.hour = 10
                AND bakery_security_logs.minute IN (16,17,18,19,20,21,22,23,24,25)
                AND bakery_security_logs.activity = 'exit'
                    AND phone_calls.duration < 60;

--Close, down to three people of whom i need two.
--Mabye look at bank statments again?
--Joining atm_trans and bank_acc on acc_num

--First find the accounts i want to look at thru people.id

SELECT id, name FROM people
    WHERE name IN ('Bruce', 'Kelsey', 'Sofia');

--Lets do one by one?

SELECT * FROM atm_transactions
    JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
    JOIN people ON bank_accounts.person_id = people.id
        WHERE people.id IN (398010, 560886, 686048);

--Bruce is the only one that used his bank account!

/*

******ANSWER******

The THIEF is: Bruce

*/

SELECT name, phone_number, caller, receiver, duration FROM bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
    JOIN phone_calls ON people.phone_number = phone_calls.caller
        WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
        AND people.passport_number IN (1695452385, 5773159633, 8294398571, 8496433585)
                AND bakery_security_logs.year = 2023
                AND bakery_security_logs.month = 7
                AND bakery_security_logs.day = 28
                AND bakery_security_logs.hour = 10
                AND bakery_security_logs.minute IN (16,17,18,19,20,21,22,23,24,25)
                AND bakery_security_logs.activity = 'exit'
                    AND phone_calls.duration < 60;

-- Just need to ID the receiver of this call activity lastly.

--Bruce called (375) 555-8161 and (455) 555-5315

SELECT * FROM people
    WHERE phone_number IN('(375) 555-8161', '(455) 555-5315');

--Only one has a passport number.
--Lets just doubble check if he was on the flight.

SELECT * FROM passengers
    WHERE passport_number = 7226911797;

--And she was not..

--Bruce phone num = '(367) 555-5533'
-- I think its the help that is wrong?
SELECT * FROM phone_calls
    WHERE caller = '(367) 555-5533'
    AND duration < 60;

SELECT * FROM people
    WHERE phone_number = '(375) 555-8161';

--Robin does not have a passport number in db but it the only call that fits with the timeframe (day) after doubble checking.
