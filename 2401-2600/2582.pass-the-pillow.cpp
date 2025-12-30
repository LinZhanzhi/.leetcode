/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution {
public:
  int passThePillow(int n, int time) {
    int cycle = n - 1;
    int t = time % (2 * cycle);
    if (t < cycle) {
      return 1 + t;
    } else {
      return n - (t - cycle);
    }
  }
};
// @lc code=end
