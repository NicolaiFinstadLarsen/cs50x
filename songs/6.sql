--write a SQL query that lists the names of songs that are by Post Malone.
--Your query should output a table with a single column for the name of each song.
--You should not make any assumptions about what Post Malone’s artist_id is.


-- Choose the name in db.songs where the colum artist_id = (choose the id from db.artist where the name == "Post Malone")
SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Post Malone');
