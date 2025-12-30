--
-- @lc app=leetcode id=1965 lang=mysql
--
-- [1965] Employees With Missing Information
--
-- @lc code=start
# Write your MySQL query statement below
(
  SELECT employee_id
  FROM Employees
  WHERE employee_id NOT IN (
      SELECT employee_id
      FROM Salaries
    )
)
UNION
(
  SELECT employee_id
  FROM Salaries
  WHERE employee_id NOT IN (
      SELECT employee_id
      FROM Employees
    )
)
ORDER BY employee_id;
-- @lc code=end