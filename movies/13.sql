--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--Your query should output a table with a single column for the name of each person.
--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.

/*
We are doing similar things as last task here \n
where we join two of the same table with two names to find \n
both Kevin Bacon id and movies he worked on id \n
We use that to find the other people that worked on that movie id
*/

SELECT DISTINCT other_people.name FROM people AS kevin
JOIN stars AS kevin_stars ON kevin.id = kevin_stars.person_id
JOIN movies AS kevin_movies ON kevin_stars.movie_id = kevin_movies.id
JOIN stars AS other_stars ON kevin_movies.id = other_stars.movie_id
JOIN people AS other_people ON other_stars.person_id = other_people.id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth IS NOT NULL
AND other_people.name != 'Kevin Bacon';


--Executing 13.sql results in a table with 1 column and 182 rows.
/*
SELECT DISTINCT COUNT(*)
FROM people AS kevin
JOIN stars AS kevin_stars ON kevin.id = kevin_stars.person_id
JOIN movies AS kevin_movies ON kevin_stars.movie_id = kevin_movies.id
JOIN stars AS other_stars ON kevin_movies.id = other_stars.movie_id
JOIN people AS other_people ON other_stars.person_id = other_people.id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth IS NOT NULL
AND other_people.name != 'Kevin Bacon';
*/
