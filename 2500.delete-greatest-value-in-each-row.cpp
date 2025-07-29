/*
 * @lc app=leetcode id=2500 lang=cpp
 *
 * [2500] Delete Greatest Value in Each Row
 */

// @lc code=start
class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // Sort each row in ascending order
    for (int i = 0; i < m; ++i) {
      sort(grid[i].begin(), grid[i].end());
    }
    int ans = 0;
    // For each column from rightmost to leftmost
    for (int col = n - 1; col >= 0; --col) {
      int mx = 0;
      for (int row = 0; row < m; ++row) {
        mx = max(mx, grid[row][col]);
      }
      ans += mx;
    }
    return ans;
  }
};
// @lc code=end
