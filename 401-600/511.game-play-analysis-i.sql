--
-- @lc app=leetcode id=511 lang=mysql
--
-- [511] Game Play Analysis I
--
-- @lc code=start
# Write your MySQL query statement below
SELECT player_id,
  MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
-- @lc code=end