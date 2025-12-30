/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfFour(int n) {
    // Check if n is positive, is a power of two, and its only set bit is at an
    // even position
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
  }
};
// @lc code=end
