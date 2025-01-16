--write a SQL query that returns the average energy of songs that are by Drake.
--Your query should output a table with a single column and a single row containing the average energy.
--You should not make any assumptions about what Drake’s artist_id is.

-- Just beeing cute with the AS nameing

SELECT AVG(energy) AS Avg_energy_Drake_songs FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = 'Drake');
