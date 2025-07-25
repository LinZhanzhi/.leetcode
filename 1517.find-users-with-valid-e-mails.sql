--
-- @lc app=leetcode id=1517 lang=mysql
--
-- [1517] Find Users With Valid E-Mails
--
-- @lc code=start
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$'
  AND BINARY RIGHT(mail, 13) = '@leetcode.com';
-- @lc code=end