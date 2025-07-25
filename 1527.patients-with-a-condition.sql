--
-- @lc app=leetcode id=1527 lang=mysql
--
-- [1527] Patients With a Condition
--
-- @lc code=start
# Write your MySQL query statement below
SELECT patient_id,
  patient_name,
  conditions
FROM Patients
WHERE conditions REGEXP '(^| )DIAB1[0-9]+';
-- only match as a word, not with a "+" or other char before
-- @lc code=end