# Write your MySQL query statement below
-- select customer_id
-- from Customer
-- group by customer_id
-- having count(distinct product_key) = (
--     select count(product_key) from Product
-- )

#===================== Using join ====================
select c.customer_id
from Customer c
left join Product p
on c.product_key = p.product_key
group by c.customer_id
having count(distinct c.product_key) = ( 
    select count(product_key) from Product
)