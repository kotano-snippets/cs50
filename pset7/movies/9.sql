SELECT name FROM
(SELECT DISTINCT person_id, name, birth FROM people
JOIN stars ON people.id=stars.person_id
JOIN movies ON stars.movie_id=movies.id
WHERE movies.year = 2004)
ORDER BY birth;