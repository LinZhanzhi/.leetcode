/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1, maxNum = n * n;
    while (num <= maxNum) {
      // left to right
      for (int i = left; i <= right && num <= maxNum; ++i) {
        matrix[top][i] = num++;
      }
      ++top;
      // top to bottom
      for (int i = top; i <= bottom && num <= maxNum; ++i) {
        matrix[i][right] = num++;
      }
      --right;
      // right to left
      for (int i = right; i >= left && num <= maxNum; --i) {
        matrix[bottom][i] = num++;
      }
      --bottom;
      // bottom to top
      for (int i = bottom; i >= top && num <= maxNum; --i) {
        matrix[i][left] = num++;
      }
      ++left;
    }
    return matrix;
  }
};
// @lc code=end
