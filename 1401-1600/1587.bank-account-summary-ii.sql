--
-- @lc app=leetcode id=1587 lang=mysql
--
-- [1587] Bank Account Summary II
--
-- @lc code=start
# Write your MySQL query statement below
SELECT u.name,
  SUM(t.amount) AS balance
FROM Users u
  JOIN Transactions t ON u.account = t.account
GROUP BY u.account,
  u.name
HAVING SUM(t.amount) > 10000;
-- @lc code=end