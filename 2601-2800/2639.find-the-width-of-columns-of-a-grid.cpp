/*
 * @lc app=leetcode id=2639 lang=cpp
 *
 * [2639] Find the Width of Columns of a Grid
 */

// @lc code=start
class Solution {
public:
  // Helper function to compute the width (number of characters) needed to
  // represent an integer
  int getNumWidth(int num) {
    if (num == 0)
      return 1;
    int len = 0;
    if (num < 0) {
      len = 1; // for the minus sign
      num = -num;
    }
    int tmp = num;
    while (tmp > 0) {
      ++len;
      tmp /= 10;
    }
    return len;
  }

  // Helper function to compute the maximum width for a given column
  int getColumnMaxWidth(const vector<vector<int>> &grid, int col) {
    int m = grid.size();
    int maxWidth = 0;
    for (int row = 0; row < m; ++row) {
      int len = getNumWidth(grid[row][col]);
      if (len > maxWidth)
        maxWidth = len;
    }
    return maxWidth;
  }

  vector<int> findColumnWidth(vector<vector<int>> &grid) {
    int n = grid[0].size();
    vector<int> ans(n, 0);
    for (int col = 0; col < n; ++col) {
      ans[col] = getColumnMaxWidth(grid, col);
    }
    return ans;
  }
};
// @lc code=end
