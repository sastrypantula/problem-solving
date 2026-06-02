# Write your MySQL query statement below
select p1.product_name,p2.year,p2.price from Product as p1 join Sales as p2 on p1.product_id=p2.product_id;