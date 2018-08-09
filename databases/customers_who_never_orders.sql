# Write your MySQL query statement below
SELECT Name AS Customers FROM (SELECT CustomerId, Name FROM Customers AS c1 LEFT JOIN Orders AS o1 ON c1.Id = o1.CustomerId) AS N WHERE N.CustomerId IS NULL