# SELECT DISTINCT a.customer_id 
# FROM Customer a 
# WHERE customer_id IN 
#     (SELECT b.customer_id 
#         FROM Customer b 
#         GROUP BY b.customer_id 
#         HAVING COUNT(DISTINCT b.product_key)=(SELECT COUNT(*) FROM Product) );
        
        SELECT DISTINCT b.customer_id 
        FROM Customer b 
        GROUP BY b.customer_id 
        HAVING COUNT(DISTINCT b.product_key)=(SELECT COUNT(*) FROM Product);