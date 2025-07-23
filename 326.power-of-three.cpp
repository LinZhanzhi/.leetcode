/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfThree(int n) {
    // The largest power of 3 that fits in a 32-bit signed integer is 3^19 =
    // 1162261467 If n > 0 and 1162261467 % n == 0, then n is a power of three
    return n > 0 && 1162261467 % n == 0;
  }
};
// @lc code=end
