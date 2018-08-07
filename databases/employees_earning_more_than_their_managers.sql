# Write your MySQL query statement below
select name Employee from Employee AS e1
where e1.Salary > (select e2.Salary from Employee AS e2 where e1.ManagerId = e2.Id)