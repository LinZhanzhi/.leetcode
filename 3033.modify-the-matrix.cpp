/*
 * @lc app=leetcode id=3033 lang=cpp
 *
 * [3033] Modify the Matrix
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
    // INSERT_YOUR_CODE
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> answer = matrix;
    vector<int> colMax(n, INT_MIN);

    // Find max in each column (excluding -1)
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        if (matrix[i][j] != -1) {
          colMax[j] = max(colMax[j], matrix[i][j]);
        }
      }
    }

    // Replace -1 with column max
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == -1) {
          answer[i][j] = colMax[j];
        }
      }
    }
    return answer;
  }
};
// @lc code=end
