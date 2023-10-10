# Write your MySQL query statement below
 (select Users.name as results
 from MovieRating
 left join Users
 on Users.user_id=MovieRating.user_id
 group by Users.user_id
 order by count(Users.user_id) desc, Users.name
 limit 1)
 UNION ALL
 (select distinct Movies.title as results
 from MovieRating
  right join Movies
  on MovieRating.movie_id=Movies.movie_id
  where created_at between '2020-02-01' and '2020-02-29'
  group by Movies.title
  order by avg(MovieRating.rating) desc, Movies.title
  limit 1
 );
 
#  (SELECT u.name AS results
# FROM MovieRating AS r
# LEFT JOIN Users AS u
# ON r.user_id = u.user_id
# GROUP BY u.name
# ORDER BY COUNT(u.user_id) DESC, u.name
# LIMIT 1)
# UNION ALL
# (SELECT DISTINCT m.title AS results
# FROM Movies AS m
# RIGHT JOIN MovieRating AS r
# ON m.movie_id = r.movie_id 
# WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
# GROUP BY m.title
# ORDER BY AVG(r.rating) DESC, m.title
# LIMIT 1)
 
 
 