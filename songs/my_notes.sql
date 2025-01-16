SELECT AVG(energy), AVG(danceability), AVG(valence) FROM songs;

SELECT AVG((energy + danceability + valence) / 3.0) AS avg FROM songs;
