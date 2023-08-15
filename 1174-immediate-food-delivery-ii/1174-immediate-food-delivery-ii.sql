# Write your MySQL query statement below
SELECT ROUND(COUNT(CASE WHEN DATEDIFF(order_date, customer_pref_delivery_date) = 0 THEN 1 ELSE NULL END) / COUNT(*) * 100, 2) AS immediate_percentage
FROM (
    SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
) AS first_orders
JOIN Delivery ON first_orders.customer_id = Delivery.customer_id AND first_orders.first_order_date = Delivery.order_date;
