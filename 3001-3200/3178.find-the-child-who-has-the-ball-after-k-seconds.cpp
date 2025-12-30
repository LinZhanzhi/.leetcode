/*
 * @lc app=leetcode id=3178 lang=cpp
 *
 * [3178] Find the Child Who Has the Ball After K Seconds
 */

// @lc code=start
class Solution {
public:
  int numberOfChild(int n, int k) {
    int cycle = n - 1;
    int t = k % (2 * cycle);
    if (t <= cycle) {
      return t;
    } else {
      return 2 * cycle - t;
    }
  }
};
// @lc code=end
