/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a 2D grid where each cell is either a battleship ('X') or empty
 * ('.'). Battleships are placed either horizontally or vertically, and no two
 * battleships touch each other (not even diagonally). Our task is to count how
 * many distinct battleships are present on the board. A battleship is a
 * contiguous sequence of 'X's in a row or column, separated from others by at
 * least one '.'.
 */

/*
 * High-Level Summary:
 * ----
 * The solution scans the board in a single pass, using O(1) extra memory and
 * without modifying the board. For each cell containing 'X', we check if it is
 * the "top-left" cell of a battleship (i.e., there is no 'X' directly above or
 * to the left). If so, we increment our battleship count. This approach ensures
 * each battleship is counted exactly once, regardless of its size or
 * orientation.
 *
 * Time Complexity: O(m * n), where m and n are the dimensions of the board.
 * Space Complexity: O(1), as we use only a constant amount of extra space.
 */

#include <vector>  // Include vector for 2D board representation
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    // Get the number of rows (m) and columns (n) in the board
    int m = board.size();
    if (m == 0)
      return 0; // Edge case: empty board
    int n = board[0].size();

    int count = 0; // Initialize the battleship counter

    // Iterate over every cell in the board
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // Skip empty cells; only process cells with 'X'
        if (board[i][j] != 'X')
          continue;

        // Check if there is an 'X' directly above; if so, this cell is part of
        // a vertical battleship already counted
        if (i > 0 && board[i - 1][j] == 'X')
          continue;

        // Check if there is an 'X' directly to the left; if so, this cell is
        // part of a horizontal battleship already counted
        if (j > 0 && board[i][j - 1] == 'X')
          continue;

        // If neither above nor left is 'X', this cell is the top-left of a new
        // battleship
        ++count;
      }
    }
    // Return the total number of battleships found
    return count;
  }
};
// @lc code=end
