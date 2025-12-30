/*
 * @lc app=leetcode id=3402 lang=cpp
 *
 * [3402] Minimum Operations to Make Columns Strictly Increasing
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      int prev = grid[0][j];
      for (int i = 1; i < m; ++i) {
        if (grid[i][j] <= prev) {
          ans += prev + 1 - grid[i][j];
          prev = prev + 1;
        } else {
          prev = grid[i][j];
        }
      }
    }
    return ans;
  }
};
// @lc code=end
