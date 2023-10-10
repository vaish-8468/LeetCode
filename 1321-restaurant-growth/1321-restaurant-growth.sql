# Write your MySQL query statement below


select 
  *
from (
  select
    distinct visited_on,
    sum(amount) over (order by visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) as amount,
    round(sum(amount) over (order by visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW)/7, 2) as average_amount
  from Customer
) j
where date_add((select min(visited_on) from Customer), interval 6 day) <= visited_on




