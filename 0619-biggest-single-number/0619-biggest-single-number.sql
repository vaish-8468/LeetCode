# Write your MySQL query statement below
select max(num) as num
from (select  num, count(num) as freq from MyNumbers group by num) as New
where New.freq=1 OR New.freq IS NULL;