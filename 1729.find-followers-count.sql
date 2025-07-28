--
-- @lc app=leetcode id=1729 lang=mysql
--
-- [1729] Find Followers Count
--
-- @lc code=start
# Write your MySQL query statement below
SELECT user_id,
  COUNT(follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC;
-- @lc code=end