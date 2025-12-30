/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;
    k = k % total;
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int idx = (i * n + j + k) % total;
        int ni = idx / n;
        int nj = idx % n;
        res[ni][nj] = grid[i][j];
      }
    }
    return res;
  }
};
// @lc code=end
