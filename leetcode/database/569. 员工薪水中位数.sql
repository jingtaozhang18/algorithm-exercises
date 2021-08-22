-- https://leetcode-cn.com/problems/median-employee-salary/
SELECT  Id
       ,Company
       ,Salary
FROM Employee
WHERE Id IN ( 
    SELECT e1.Id 
    FROM Employee e1 JOIN Employee e2 ON e1.Company = e2.Company 
    GROUP BY e1.Id 
    HAVING SUM(CASE WHEN e1.Salary >= e2.Salary THEN 1 ELSE 0 END) >= COUNT(*)/2 AND SUM(CASE WHEN e1.Salary <= e2.Salary THEN 1 ELSE 0 END) >= COUNT(*)/2 )
GROUP BY  Company
         ,Salary
ORDER BY Company
-- 作者：john-lee-9
-- 链接：https://leetcode-cn.com/problems/median-employee-salary/solution/bu-gua-yong-ren-he-sqlnei-zhi-han-shu-jie-fa-xiang/
-- 来源：力扣（LeetCode）
-- 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。