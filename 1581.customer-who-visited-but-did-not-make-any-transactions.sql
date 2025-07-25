--
-- @lc app=leetcode id=1581 lang=mysql
--
-- [1581] Customer Who Visited but Did Not Make Any Transactions
--
-- @lc code=start
# Write your MySQL query statement below
SELECT customer_id,
  COUNT(*) AS count_no_trans
FROM Visits v
  LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id;
-- @lc code=end