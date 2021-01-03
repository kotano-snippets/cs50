SELECT title
FROM
(
SELECT movie_id, title, COUNT(movie_id) as n
FROM stars
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name IN ("Johnny Depp", "Helena Bonham Carter")
GROUP BY movie_id
)
WHERE n = 2;