-- https://leetcode-cn.com/problems/nth-highest-salary/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N := N-1;
  RETURN (
      SELECT 
            Salary
      FROM 
            Employee
      GROUP BY 
            Salary
      ORDER BY 
            Salary DESC
      LIMIT N, 1
  );
END