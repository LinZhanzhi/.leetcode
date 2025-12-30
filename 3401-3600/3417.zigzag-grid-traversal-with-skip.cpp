/*
 * @lc app=leetcode id=3417 lang=cpp
 *
 * [3417] Zigzag Grid Traversal With Skip
 */

// @lc code=start
class Solution {
public:
  vector<int> zigzagTraversal(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> filtered;
    for (int i = 0; i < n * m; ++i) {
      if (i % 2 == 0) {
        int row = i / n;
        int col = i % n;
        if (row % 2 == 0) {
          filtered.push_back(grid[row][col]);
        } else {
          filtered.push_back(grid[row][n - col - 1]);
        }
      }
    }
    return filtered;
  }
};
// @lc code=end
