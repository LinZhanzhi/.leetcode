--
-- @lc app=leetcode id=3465 lang=mysql
--
-- [3465] Find Products with Valid Serial Numbers
--
-- @lc code=start
# Write your MySQL query statement below
SELECT *
FROM products
WHERE REGEXP_LIKE(
    description,
    '\\bSN[0-9]{4}-[0-9]{4}\\b',
    'c'
  )
ORDER BY product_id;
-- @lc code=end