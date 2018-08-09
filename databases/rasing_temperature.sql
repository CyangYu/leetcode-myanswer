# Write your MySQL query statement below
 SELECT w1.Id FROM Weather AS w1 INNER JOIN Weather w2 ON datediff(w1.RecordDate, w2.RecordDate) = 1 AND w1.Temperature > w2.Temperature;