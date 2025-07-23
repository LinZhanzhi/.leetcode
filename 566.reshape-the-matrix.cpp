/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c) {
      return mat;
    }
    vector<vector<int>> result(r, vector<int>(c));
    for (int i = 0; i < m * n; ++i) {
      result[i / c][i % c] = mat[i / n][i % n];
    }
    return result;
  }
};
// @lc code=end
