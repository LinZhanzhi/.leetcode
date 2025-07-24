--
-- @lc app=leetcode id=1141 lang=mysql
--
-- [1141] User Activity for the Past 30 Days I
--
-- @lc code=start
-- Select the activity date as 'day' and count the number of distinct users active on each day
SELECT activity_date AS day,
  COUNT(DISTINCT user_id) AS active_users
FROM Activity -- Filter for activities within the last 30 days up to and including '2019-07-27'
WHERE activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 DAY)
  AND '2019-07-27' -- Group the results by each activity date to get daily active users
GROUP BY activity_date;
-- @lc code=end