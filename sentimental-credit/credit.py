'''
TODO
Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
Make alle the card with their argument
Check for what card and print it
'''


def main():

    x = get_int("Number: ")

    extracted_numbers = extract_every_2nd_number(x)
    non_extraced_numbers = find_the_non_extracted_numbers(x)

    total_of_extracted_numbers = multiplying_extracted_numbers(extracted_numbers)
    total_of_the_non_extracted_numbers = sum_of_non_extraced_numbers(non_extraced_numbers)

    total_number = total_of_extracted_numbers + total_of_the_non_extracted_numbers
    valid_check = valid_card_check(total_number)

    if valid_check == 0:
        # print("Yes!")
        # print(x)
        card_type(x)
    else:
        print("INVALID")


'''
    print(f"The sum of the extraced numbers multiplied with 2 \
are: {total_of_extracted_numbers}")

    print(f"The sum of the non extraced numbers \
are: {total_of_the_non_extracted_numbers}")
'''


# Checking card type
# Checking both length and starting number
def card_type(number):
    # converting input number to a string of single digit numbers concat to a single string with .join method
    # We make an empty string and joins it with every number
    # Using the map funtion to apply str type to each itterable in number
    # map works like this map(function, iterable, ...)
    number_str = "".join(map(str, number))

    # Creating the different cards with their length and start number arguments.
    # Using two entries for VISA since there are two lengths
    card_types = [
        ("MASTERCARD", 16, ["51", "52", "53", "54", "55"]),
        ("AMEX", 15, ["34", "37"]),
        ("VISA", 13, ["4"]),
        ("VISA", 16, ["4"])
    ]

    # Cheching the length and start number in the input number against the cards from above
    # The any argument is not good to use without a list or string.
    # That is why we used two entries for VISA when there is two lengths
    # The any argument is used to itterate and check all the start numbers for the card entries.
    # It just needs to match any of them.
    for card, length, prefixes in card_types:
        if len(number) == length and any(number_str.startswith(prefix) for prefix in prefixes):
            # Printing the corresponding card.
            print(card)
            return
        print("INVALID")


# The code under was my first attempt.
# The code above is the improved version with some rubberducking help.
'''
    # Checing len of input and starting digit with .startswith method for stings
    if len(number) == 16 and number_str.startswith("51") or number_str.startswith("52") or number_str.startswith("53") or number_str.startswith("54") or number_str.startswith("55"):
        print("MASTERCARD")
        return
    if len(number) == 15 and number_str.startswith("34") or number_str.startswith("37"):
        print("AMEX")
        return
    if len(number) == 13 or len(number) == 16 and number_str.startswith("4"):
        print("VISA")
        return
'''

# Checking is the last number
# A valid number ends with 0 after the checksum function


def valid_card_check(number):
    valid_check = number % 10
    return valid_check


# Multiply every 2nd number starting from 2nd last.
def extract_every_2nd_number(number):
    extracted_numbers = [number[i] for i in range(len(number) - 2, -1, -2)]
    return extracted_numbers


def multiplying_extracted_numbers(number):
    # Return the sum of the exctracted numbers multiplied by 2.
    multiplied = [x*2 for x in number]
    # Creating the needed list
    digits = []
    # converting the number to a string since we need single digits \n
    # if there was any double digits after multiplied
    # Extending the list insted of appending the whole number.
    # Extending adds one and one number.
    for n in multiplied:
        digits.extend([int(digit) for digit in str(n)])
    return sum(digits)


# Summing up the numbers that did not need to be extracted
def find_the_non_extracted_numbers(number):
    non_extracted_numbers = [number[i] for i in range(len(number) - 1, -1, -2)]
    return non_extracted_numbers


# Return the sum of the non exctracted numbers.
def sum_of_non_extraced_numbers(number):
    return sum(number)


# Getting the number we are going to check
def get_int(prompt):
    while True:
        try:
            # Changing it to a list of int's
            f = input(prompt)
            newlist = [int(x) for x in f]
            return newlist

        except ValueError:
            print("NaN, use int.")
            pass


main()
