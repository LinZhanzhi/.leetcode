/*
 * @lc app=leetcode id=3345 lang=cpp
 *
 * [3345] Smallest Divisible Digit Product I
 */

// @lc code=start
class Solution {
public:
  int smallestNumber(int n, int t) {
    for (int x = n;; ++x) {
      int prod = 1;
      int y = x;
      bool has_zero = false;
      if (y == 0)
        prod = 0;
      while (y > 0) {
        int d = y % 10;
        if (d == 0) {
          prod = 0;
          break;
        }
        prod *= d;
        y /= 10;
      }
      if (prod % t == 0)
        return x;
    }
  }
};
// @lc code=end
