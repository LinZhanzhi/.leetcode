--
-- @lc app=leetcode id=1789 lang=mysql
--
-- [1789] Primary Department for Each Employee
--
-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id,
  department_id
FROM Employee
WHERE primary_flag = 'Y'
  OR employee_id IN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
  );
-- @lc code=end