/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The Minesweeper problem asks us to simulate a single click on a Minesweeper
 * board. If the click is on a mine ('M'), we reveal it as 'X' and the game
 * ends. If the click is on an empty square ('E'), we reveal it:
 *   - If there are no adjacent mines, we mark it as 'B' and recursively reveal
 * all adjacent unrevealed squares.
 *   - If there are adjacent mines, we mark it with the number of adjacent mines
 * ('1'-'8'). The process continues recursively until no more squares can be
 * revealed.
 *
 * High-Level Summary:
 * ----
 * The solution uses Depth-First Search (DFS) to reveal squares recursively.
 * - We first check the clicked cell: if it's a mine, we mark it as 'X'.
 * - If it's an empty cell, we count adjacent mines.
 *   - If there are adjacent mines, we set the cell to the count.
 *   - If not, we set it to 'B' and recursively reveal all adjacent unrevealed
 * cells. The algorithm ensures we do not revisit already revealed cells.
 *
 * Time Complexity: O(m * n) in the worst case (all cells revealed).
 * Space Complexity: O(m * n) for the recursion stack in the worst case.
 */

#include <vector>  // For std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  // Main function to update the board after a click
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    int m = board.size();    // Number of rows
    int n = board[0].size(); // Number of columns
    int row = click[0], col = click[1];

    // If the clicked cell is a mine, reveal it as 'X' and return
    if (board[row][col] == 'M') {
      board[row][col] = 'X';
      return board;
    }

    // Otherwise, start DFS from the clicked cell
    dfs(board, row, col, m, n);
    return board;
  }

private:
  // Directions for 8 adjacent cells (up, down, left, right, and diagonals)
  const vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  // Helper function to count adjacent mines around (row, col)
  int countAdjacentMines(const vector<vector<char>> &board, int row, int col,
                         int m, int n) {
    int count = 0;
    for (const auto &dir : directions) {
      int newRow = row + dir[0];
      int newCol = col + dir[1];
      // Check if the adjacent cell is within bounds and is a mine
      if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
          board[newRow][newCol] == 'M') {
        count++;
      }
    }
    return count;
  }

  // DFS function to reveal cells recursively
  void dfs(vector<vector<char>> &board, int row, int col, int m, int n) {
    // If out of bounds or not an unrevealed empty cell, do nothing
    if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'E') {
      return;
    }

    // Count adjacent mines
    int mineCount = countAdjacentMines(board, row, col, m, n);

    if (mineCount > 0) {
      // If there are adjacent mines, set the cell to the count ('1'-'8')
      board[row][col] = '0' + mineCount;
    } else {
      // If no adjacent mines, set to 'B' and recursively reveal neighbors
      board[row][col] = 'B';
      for (const auto &dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];
        dfs(board, newRow, newCol, m, n);
      }
    }
  }
};
// @lc code=end
