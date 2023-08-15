# Write your MySQL query statement below
select date_format(trans_date,'%Y-%m') AS month, country,  count(state) as trans_count, sum(if(state='approved',1,0)) AS approved_count, sum(amount) AS trans_total_amount, sum(if(state='approved', amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY month, country;