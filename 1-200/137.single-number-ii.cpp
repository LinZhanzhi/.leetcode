/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
      ones = (ones ^ num) & ~twos;
      twos = (twos ^ num) & ~ones;
    }
    return ones;
  }
  // The function uses two variables, 'ones' and 'twos', to track the bits that
  // have appeared once and twice, respectively. For each number in the array:
  //   - 'ones' holds the bits which have appeared exactly once so far
  //   (excluding those that have appeared three times).
  //   - 'twos' holds the bits which have appeared exactly twice so far
  //   (excluding those that have appeared three times).
  // The key idea is that for every bit position, its count modulo 3 is tracked
  // using these two variables. At the end, 'ones' contains the unique number
  // that appears only once.
};
// @lc code=end
