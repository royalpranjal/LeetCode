# Write your MySQL query statement below
SELECT Customers.Name AS Customers FROM (Customers LEFT OUTER JOIN Orders ON Customers.Id = Orders.CustomerId) WHERE Orders.CustomerId IS NULL;
