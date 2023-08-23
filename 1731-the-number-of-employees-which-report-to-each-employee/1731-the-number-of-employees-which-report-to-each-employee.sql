# Write your MySQL query statement below

select  a.employee_id, a.name, count(b.employee_id) as reports_count, round(avg(b.Age),0) AS average_age
from Employees a
JOIN Employees b
ON a.employee_id=b.reports_to
Group By a.employee_id
Order By a.employee_id;