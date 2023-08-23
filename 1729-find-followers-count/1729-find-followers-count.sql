# Write your MySQL query statement below

SELECT DISTINCT user_id, count(follower_id) as followers_count
FROM Followers
Group BY user_id 
ORDER BY user_id ASC;