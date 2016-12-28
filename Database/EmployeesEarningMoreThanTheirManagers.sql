# Write your MySQL query statement below
SELECT a.Name As Employee FROM ((Employee AS a) INNER JOIN (Employee AS b) ON a.ManagerId = b.Id) WHERE a.Salary > b.Salary
