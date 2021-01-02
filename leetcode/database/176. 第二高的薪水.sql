-- https://leetcode-cn.com/problems/second-highest-salary/

-- 官方解法
-- 使用临时表来保证返回NULL
SELECT 
(
  SELECT DISTINCT(Salary) FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1
) AS SecondHighestSalary;

-- 官方解法
-- 使用IFNULL判断语句
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary