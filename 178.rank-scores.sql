--
-- @lc app=leetcode id=178 lang=mysql
--
-- [178] Rank Scores
--
-- @lc code=start
# Write your MySQL query statement below
SELECT score,
  DENSE_RANK() OVER (
    ORDER BY score DESC
  ) AS 'rank'
FROM Scores
ORDER BY score DESC;
-- @lc code=end