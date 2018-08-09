# Write your MySQL query statement below
DELETE FROM Person WHERE Id IN (SELECT n.Id FROM (SELECT p2.* FROM Person AS p1 INNER JOIN Person AS p2 ON p2.Id > p1.Id AND p1.Email = p2.Email) AS n);