--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--
-- @lc code=start
# Write your MySQL query statement below
SELECT name AS Employee
FROM Employee e1
WHERE EXISTS (
    SELECT 1
    FROM Employee e2
    WHERE e2.id = e1.managerId
      AND e1.salary > e2.salary
  );
-- @lc code=end