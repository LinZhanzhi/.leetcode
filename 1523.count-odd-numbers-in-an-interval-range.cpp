/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
  int countOdds(int low, int high) {
    // The number of odd numbers between low and high inclusive is:
    // (high + 1) / 2 - (low / 2)
    return (high + 1) / 2 - (low / 2);
  }
};
// @lc code=end
