# Write your MySQL query statement below
SELECT CASE
           WHEN s.id % 2 <> 0 AND s.id = (SELECT COUNT(*) FROM Seat) THEN s.id  
           # If the current "id" (s.id) is odd (s.id % 2 <> 0) and equal to the count of rows in the "Seat" table (i.e., it's the last row), then it selects the current "id"                   (s.id) as is.
           WHEN s.id % 2 = 0 THEN s.id - 1
           ELSE
               s.id + 1
           END AS id,
       student
FROM Seat AS s
ORDER BY id;