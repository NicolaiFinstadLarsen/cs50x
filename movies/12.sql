--write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Bradley Cooper.
--You may assume that there is only one person in the database with the name Jennifer Lawrence.

/*
Here we needed to "self join" as in joining the same table to each other twice over and using two different names for each table \n
That is the only way i could find both names since i would need two tables for that. \n
It's longer since i needed to find the person.id from stars first.
*/

SELECT title FROM movies
JOIN stars AS stars_b ON movies.id = stars_b.movie_id
JOIN stars AS stars_j ON movies.id = stars_j.movie_id
JOIN people AS people_b ON stars_b.person_id = people_b.id
JOIN people AS people_j ON stars_j.person_id = people_j.id
WHERE people_j.name = 'Jennifer Lawrence'
AND people_b.name = 'Bradley Cooper'
LIMIT 15;

--Executing 12.sql results in a table with 1 column and 4 rows.
/*
SELECT COUNT(*) FROM movies
JOIN stars AS stars_b ON movies.id = stars_b.movie_id
JOIN stars AS stars_j ON movies.id = stars_j.movie_id
JOIN people AS people_b ON stars_b.person_id = people_b.id
JOIN people AS people_j ON stars_j.person_id = people_j.id
WHERE people_j.name = 'Jennifer Lawrence'
AND people_b.name = 'Bradley Cooper'
LIMIT 15;
*/

