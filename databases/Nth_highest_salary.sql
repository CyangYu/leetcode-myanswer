CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      CREATE TEMPORARY TABLE temp_table (
          Id, INT, 
          Salary Salary
      );

      INSERT INTO temp_table (Id, Salary) VALUES (SELECT Id, Salary FROM Employee ORDER BY Salary DESC);
      IF COUNT(temp_table) < N
      BEGIN
        
  );
END