-- https://leetcode-cn.com/problems/trips-and-users/

-- 题解解法，注意聚合之后的操作和JOIN ON语句的含义理解
-- 303ms
SELECT Request_at as `Day`, 
  ROUND(
    SUM(
      if(T.Status='completed', 0, 1))
      /
      COUNT(T.Status),
      2
  ) AS `Cancellation Rate`
FROM Trips AS T
JOIN Users AS U1 ON(T.Client_Id=U1.Users_Id AND U1.Banned='No')
JOIN Users AS U2 ON(T.Driver_Id=U2.Users_Id AND U2.Banned='No')
WHERE T.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at ORDER BY Request_at ASC

-- 另外一种判断ID是否合法的方式
-- 347ms
SELECT Request_at as `Day`, 
  ROUND(
    SUM(
      if(T.Status='completed', 0, 1))
      /
      COUNT(T.Status),
      2
  ) AS `Cancellation Rate`
FROM Trips AS T
WHERE T.Request_at BETWEEN '2013-10-01' AND '2013-10-03' AND
  T.Client_Id not in (SELECT Users_Id FROM Users WHERE Banned='Yes') AND
  T.Driver_Id not in (SELECT Users_Id FROM Users WHERE Banned='Yes')
GROUP BY Request_at ORDER BY Request_at ASC