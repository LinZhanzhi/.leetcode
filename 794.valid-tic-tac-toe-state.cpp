/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// Brief Digested Understanding:
// ----
// The goal is to determine whether a given 3x3 tic-tac-toe board could have
// resulted from a sequence of valid moves, following the standard rules of the
// game. The essential challenges are verifying that X and O have been played
// with the correct turn order, that no player has extra moves, and that no
// moves have happened after the game is already won.

// High-Level Summary:
// ----
// The solution will count the number of X's and O's on the board, verify that
// the play order is correct (X always first, turn counts are compatible),
// check whether X or O has a win and ensure that both cannot win at once,
// and that no moves were made after a win. The key checks are:
//   - X starts first, so X's count is always >= O's, and never > O's+1.
//   - If X won, X's count must be exactly one more than O's.
//   - If O won, X's and O's counts must be equal.
//   - Both X and O cannot win at the same time.
// This approach leverages helper functions to detect wins and perform board
// counting. The solution runs in O(1) time and space (since the board is 3x3).

#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Checks if the given board state is valid according to the rules
  bool validTicTacToe(vector<string> &board) {
    int xCount = 0, oCount = 0;
    // Count number of X's and O's on the board
    countMarks(board, xCount, oCount);

    // X always goes first, and alternate turns, so xCount must be >= oCount
    // And xCount can't be more than oCount + 1
    if (oCount > xCount || xCount > oCount + 1)
      return false;

    // Check if X or O has a winning line
    bool xWin = hasWon(board, 'X');
    bool oWin = hasWon(board, 'O');

    // Both players can't win at the same time
    if (xWin && oWin)
      return false;

    // If X wins, X must have played one more time than O
    if (xWin && xCount != oCount + 1)
      return false;

    // If O wins, must have same number of X's and O's
    if (oWin && xCount != oCount)
      return false;

    // If passes all checks, is a valid state
    return true;
  }

private:
  // Helper function to count number of 'X' and 'O' on the board
  void countMarks(const vector<string> &board, int &xCount, int &oCount) {
    xCount = 0;
    oCount = 0;
    // Iterate over each cell in the 3x3 board
    for (const string &row : board) {
      for (char c : row) {
        if (c == 'X')
          ++xCount;
        else if (c == 'O')
          ++oCount;
      }
    }
    // Counts are returned via reference arguments
  }

  // Helper function to determine if the given player ('X' or 'O') has a win
  bool hasWon(const vector<string> &board, char player) {
    // Check all possible rows, columns, and diagonals for a win
    // Since the board is 3x3, it's simple to check all possibilities
    for (int i = 0; i < 3; ++i) {
      // Check rows
      if (board[i][0] == player && board[i][1] == player &&
          board[i][2] == player)
        return true;
      // Check columns
      if (board[0][i] == player && board[1][i] == player &&
          board[2][i] == player)
        return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
      return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
      return true;
    // If no winning line is found, return false
    return false;
  }
};
// @lc code=end
