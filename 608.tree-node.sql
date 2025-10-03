--
-- @lc app=leetcode id=608 lang=mysql
--
-- [608] Tree Node
--
-- @lc code=start
# Write your MySQL query statement below
SELECT id,
  CASE
    WHEN p_id IS NULL THEN 'Root'
    WHEN id IN (
      SELECT p_id
      FROM Tree
      WHERE p_id IS NOT NULL
    ) THEN 'Inner'
    ELSE 'Leaf'
  END AS type
FROM Tree -- @lc code=end