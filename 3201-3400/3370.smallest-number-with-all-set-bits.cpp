/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution {
public:
  int smallestNumber(int n) {
    // The smallest number >= n with all set bits is the smallest number of the
    // form (2^k - 1) >= n
    int x = 1;
    while ((x - 1) < n) {
      x <<= 1;
    }
    return x - 1;
  }
};
// @lc code=end
