/*
 * @lc app=leetcode id=2119 lang=cpp
 *
 * [2119] A Number After a Double Reversal
 */

// @lc code=start
class Solution {
public:
  bool isSameAfterReversals(int num) {
    // If num is 0, double reversal will always be 0
    if (num == 0)
      return true;
    // If num ends with 0, after first reversal, leading zeros are dropped, so
    // double reversal will not be equal
    if (num % 10 == 0)
      return false;
    // Otherwise, double reversal will always be equal to num
    return true;
  }
};
// @lc code=end
