/*
 * @lc app=leetcode id=3200 lang=cpp
 *
 * [3200] Maximum Height of a Triangle
 */

// @lc code=start
class Solution {
public:
  int maxHeightOfTriangle(int red, int blue) {
    int maxHeight = 0;
    // Try both starting colors: 0 for red, 1 for blue
    for (int start = 0; start < 2; ++start) {
      int r = red, b = blue;
      int h = 0;
      int turn = start;
      for (int row = 1;; ++row) {
        if (turn == 0) { // red's turn
          if (r >= row) {
            r -= row;
          } else {
            break;
          }
        } else { // blue's turn
          if (b >= row) {
            b -= row;
          } else {
            break;
          }
        }
        ++h;
        turn ^= 1;
      }
      if (h > maxHeight)
        maxHeight = h;
    }
    return maxHeight;
  }
};
// @lc code=end
