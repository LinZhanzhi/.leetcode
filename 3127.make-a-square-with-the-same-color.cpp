/*
 * @lc app=leetcode id=3127 lang=cpp
 *
 * [3127] Make a Square with the Same Color
 */

// @lc code=start
class Solution {
public:
  bool canMakeSquare(vector<vector<char>> &grid) {
    // Check all 2x2 squares in the 3x3 grid
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int b = 0, w = 0;
        for (int x = i; x < i + 2; ++x) {
          for (int y = j; y < j + 2; ++y) {
            if (grid[x][y] == 'B')
              ++b;
            else
              ++w;
          }
        }
        // If at least 3 cells are the same, we can make all 4 the same with at
        // most one change
        if (b >= 3 || w >= 3)
          return true;
      }
    }
    return false;
  }
};
// @lc code=end
