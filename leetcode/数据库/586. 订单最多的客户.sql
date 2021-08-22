-- https://leetcode-cn.com/problems/customer-placing-the-largest-number-of-orders/
-- 无法处理并列第一的情况
SELECT  customer_number
FROM orders
GROUP BY  customer_number
ORDER BY COUNT(customer_number) desc
LIMIT 1;
-- 可以处理并列第一的情况
SELECT  customer_number
FROM orders
GROUP BY  customer_number
HAVING COUNT(customer_number) = (
SELECT  COUNT(*) AS c
FROM orders
GROUP BY  customer_number
ORDER BY COUNT(customer_number) desc
LIMIT 0, 1 );