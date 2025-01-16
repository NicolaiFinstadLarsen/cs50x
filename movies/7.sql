--write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
--Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
--Movies that do not have ratings should not be included in the result.

/*
In SQL, the ORDER BY clause processes the columns in the order they are listed.
So, it first sorts by rating in descending order, and then it sorts by title in ascending order for any rows with the same rating.
*/

-- CHOOSE title and rating collum FROM table(movies) and JOIN table(ratings) ON collum movies id with table(ratings)collum movie_id And Only show movies that are from the year 2010 and when the rating has a number Sort by rating descending and after that title ascending.
SELECT title, rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;

--Executing 7.sql results in a table with 2 columns and 7,192 rows.
--SELECT COUNT(*) FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;
