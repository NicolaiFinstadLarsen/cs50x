--write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Chadwick Boseman.

--Using left join to include movies without rating, not necessary but a learning tool
SELECT title FROM movies
LEFT JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;

--Sånn kan jeg få med rating, siden ratings er joined
/*
SELECT title, rating FROM movies
LEFT JOIN ratings ON movies.id = ratings.movie_id
LEFT JOIN stars ON movies.id = stars.movie_id
LEFT JOIN people ON people.id = stars.person_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;
*/
