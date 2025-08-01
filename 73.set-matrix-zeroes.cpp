/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Check if first row has zero
    for (int j = 0; j < n; ++j) {
      if (matrix[0][j] == 0) {
        firstRowZero = true;
        break;
      }
    }
    // Check if first column has zero
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        firstColZero = true;
        break;
      }
    }
    // Use first row and column to mark zero rows and columns
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // Set zeroes based on marks
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    // Set first row to zero if needed
    if (firstRowZero) {
      for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
      }
    }
    // Set first column to zero if needed
    if (firstColZero) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
// @lc code=end
