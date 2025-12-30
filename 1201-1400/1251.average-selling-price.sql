--
-- @lc app=leetcode id=1251 lang=mysql
--
-- [1251] Average Selling Price
--
-- @lc code=start
-- Write your MySQL query statement below
SELECT p.product_id,
  -- Calculate the average price, rounding to 2 decimals, and return 0 if no units sold
  ROUND(
    IFNULL(
      SUM(u.units * pr.price) / NULLIF(SUM(u.units), 0),
      0
    ),
    2
  ) AS average_price
FROM (
    -- Get all unique product_ids from Prices
    SELECT DISTINCT product_id
    FROM Prices
  ) p -- Join UnitsSold to get units sold for each product
  LEFT JOIN UnitsSold u ON p.product_id = u.product_id -- Join Prices to get the price for each unit sold within the price's date range
  LEFT JOIN Prices pr ON u.product_id = pr.product_id
  AND u.purchase_date BETWEEN pr.start_date AND pr.end_date
GROUP BY p.product_id;
-- @lc code=end