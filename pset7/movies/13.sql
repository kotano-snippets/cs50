SELECT DISTINCT name
FROM stars
JOIN people ON stars.person_id = people.id
WHERE NOT people.name = "Kevin Bacon" AND movie_id IN
(
SELECT movie_id
FROM stars
JOIN people ON stars.person_id = people.id
WHERE people.name = "Kevin Bacon"
AND people.birth = 1958
);