--write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
--Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
--You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.

--No % in front of Harry so to make the string start with Harry Potter.
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;


--SELECT COUNT(*) FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year;
