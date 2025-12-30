/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rowMin(m, INT_MAX);
    vector<int> colMax(n, INT_MIN);

    // Find min in each row
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        rowMin[i] = min(rowMin[i], matrix[i][j]);
      }
    }

    // Find max in each column
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        colMax[j] = max(colMax[j], matrix[i][j]);
      }
    }

    // Check for lucky numbers
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
          res.push_back(matrix[i][j]);
        }
      }
    }
    return res;
  }
};
// @lc code=end
