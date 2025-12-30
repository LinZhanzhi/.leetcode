/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    // Check rows, columns, and 3x3 sub-boxes for duplicates
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.')
          continue;
        int num = board[i][j] - '1'; // 0-based index for digit
        int boxIdx = (i / 3) * 3 + (j / 3);
        if (row[i][num] || col[j][num] || box[boxIdx][num]) {
          return false;
        }
        row[i][num] = true;
        col[j][num] = true;
        box[boxIdx][num] = true;
      }
    }
    return true;
  }
};
// @lc code=end
