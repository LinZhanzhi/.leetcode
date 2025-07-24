/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    int rookRow = -1, rookCol = -1;
    // Find the rook's position
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          rookRow = i;
          rookCol = j;
          break;
        }
      }
      if (rookRow != -1)
        break;
    }
    int captures = 0;
    // Directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int d = 0; d < 4; ++d) {
      int x = rookRow, y = rookCol;
      while (true) {
        x += dirs[d][0];
        y += dirs[d][1];
        if (x < 0 || x >= 8 || y < 0 || y >= 8)
          break;
        if (board[x][y] == 'B')
          break;
        if (board[x][y] == 'p') {
          ++captures;
          break;
        }
      }
    }
    return captures;
  }
};
// @lc code=end
