/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
  int surfaceArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int area = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0) {
          // Each stack contributes 6*count - 2*(count-1) = 4*count + 2
          area += 4 * grid[i][j] + 2;
          // Subtract the area of faces shared with the stack above (i-1, j)
          if (i > 0) {
            area -= 2 * std::min(grid[i][j], grid[i - 1][j]);
          }
          // Subtract the area of faces shared with the stack to the left (i,
          // j-1)
          if (j > 0) {
            area -= 2 * std::min(grid[i][j], grid[i][j - 1]);
          }
        }
      }
    }
    return area;
  }
};
// @lc code=end
