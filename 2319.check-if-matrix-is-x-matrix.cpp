/*
 * @lc app=leetcode id=2319 lang=cpp
 *
 * [2319] Check if Matrix Is X-Matrix
 */

// @lc code=start
class Solution {
public:
  bool checkXMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || i + j == n - 1) {
          // On a diagonal, must be non-zero
          if (grid[i][j] == 0)
            return false;
        } else {
          // Not on a diagonal, must be zero
          if (grid[i][j] != 0)
            return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
