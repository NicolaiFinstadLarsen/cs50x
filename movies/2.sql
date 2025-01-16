--write a SQL query to determine the birth year of Emma Stone.
--Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
--You may assume that there is only one person in the database with the name Emma Stone.

SELECT birth as Birthyear FROM people WHERE name = 'Emma Stone';

--SELECT (2024 - birth) as Age FROM people WHERE name = 'Emma Stone';
