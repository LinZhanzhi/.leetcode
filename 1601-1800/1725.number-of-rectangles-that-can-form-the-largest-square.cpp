/*
 * @lc app=leetcode id=1725 lang=cpp
 *
 * [1725] Number Of Rectangles That Can Form The Largest Square
 */

// @lc code=start
class Solution {
public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int maxLen = 0;
    int count = 0;
    for (const auto &rect : rectangles) {
      int side = min(rect[0], rect[1]);
      if (side > maxLen) {
        maxLen = side;
        count = 1;
      } else if (side == maxLen) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
