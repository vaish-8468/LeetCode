# Write your MySQL query statement below
SELECT x.machine_id, ROUND(SUM(y.timestamp - x.timestamp) / COUNT(DISTINCT x.process_id), 3) AS processing_time
FROM Activity x
JOIN Activity y
ON x.machine_id=y.machine_id AND x.process_id=y.process_id AND x.activity_type='start' AND y.activity_type='end' 
WHERE x.timestamp<y.timestamp
GROUP BY x.machine_id;