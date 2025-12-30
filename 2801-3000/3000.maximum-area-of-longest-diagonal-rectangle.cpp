/*
 * @lc app=leetcode id=3000 lang=cpp
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int maxDiagSq = 0;
    int maxArea = 0;
    for (const auto &rect : dimensions) {
      int l = rect[0], w = rect[1];
      int diagSq = l * l + w * w;
      int area = l * w;
      if (diagSq > maxDiagSq) {
        maxDiagSq = diagSq;
        maxArea = area;
      } else if (diagSq == maxDiagSq) {
        if (area > maxArea) {
          maxArea = area;
        }
      }
    }
    return maxArea;
  }
};
// @lc code=end
