--
-- @lc app=leetcode id=627 lang=mysql
--
-- [627] Swap Salary
--
-- @lc code=start
# Write your MySQL query statement below
UPDATE Salary
SET sex = CASE
    WHEN sex = 'm' THEN 'f'
    WHEN sex = 'f' THEN 'm'
    ELSE sex
  END;
-- @lc code=end