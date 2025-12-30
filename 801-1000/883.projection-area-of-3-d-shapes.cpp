/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
  int projectionArea(vector<vector<int>> &grid) {
    // m is the number of rows, n is the number of columns
    int m = grid.size();
    if (m == 0)
      return 0;
    // n is the number of columns
    int n = grid[0].size();
    int area = 0;

    // Top view: count non-zero cells
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0)
          area++;
      }
    }

    // xz-plane: max height for a given x across y
    for (int i = 0; i < m; ++i) {
      int maxRow = 0;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > maxRow)
          maxRow = grid[i][j];
      }
      area += maxRow;
    }

    // yz-plane: max height for a given y across x
    for (int j = 0; j < n; ++j) {
      int maxCol = 0;
      for (int i = 0; i < m; ++i) {
        if (grid[i][j] > maxCol)
          maxCol = grid[i][j];
      }
      area += maxCol;
    }

    return area;
  }
};
// @lc code=end
