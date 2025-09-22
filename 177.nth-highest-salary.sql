--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN RETURN (
  SELECT DISTINCT salary
  FROM Employee
  ORDER BY salary DESC
  LIMIT N -1, 1
);
END -- @lc code=end