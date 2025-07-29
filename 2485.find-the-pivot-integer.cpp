/*
 * @lc app=leetcode id=2485 lang=cpp
 *
 * [2485] Find the Pivot Integer
 */

// @lc code=start
class Solution {
public:
  int pivotInteger(int n) {
    int total = n * (n + 1) / 2;
    int x = sqrt(total);
    if (x * x == total) {
      return x;
    }
    return -1;
  }
};
// @lc code=end
