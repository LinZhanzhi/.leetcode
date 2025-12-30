/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// Brief Digested Understanding:
// ----
// This problem is about identifying all 3x3 subgrids (submatrices) in a given
// 2D integer grid that are "magic squares." A 3x3 magic square must use all the
// numbers from 1 to 9 (each exactly once), and all rows, columns, and the two
// diagonals must sum to the same value. The challenge is to scan every possible
// 3x3 window in the grid, check if it contains all numbers 1-9 exactly once,
// and confirm that its sums match the "magic" requirement (which is always 15
// for a 3x3 square made from 1-9). Importantly, the original grid might
// contain out-of-range numbers or duplicates, so each candidate window must be
// carefully validated.

// High-Level Summary:
// ----
// We will iterate over every possible 3x3 subgrid within the given grid. For
// each candidate 3x3 window, we will:
//   1. Collect its 9 elements and check if they are all distinct and between 1
//   and 9.
//   2. If so, verify all rows, columns, and both diagonals sum to 15.
// The approach uses simple loops; helper functions encapsulate checking for a
// valid 1-9 set and for the "magic sum" property. Time complexity is O(R*C),
// since we check (R-2)*(C-2) windows and each check is O(1) (since the window
// size is constant at 3x3). Space complexity is O(1).
// We include all standard headers and use std::vector for 2D arrays.

// @lc code=start
#include <algorithm> // For std::fill
#include <vector>    // For std::vector

using std::vector;

class Solution {
public:
  // Main function to count all magic squares in the grid
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int R = grid.size(); // Number of rows
    if (R < 3)
      return 0;             // Not enough rows for a 3x3 square
    int C = grid[0].size(); // Number of columns
    if (C < 3)
      return 0; // Not enough columns for a 3x3 square

    int count = 0; // Counter for magic squares

    // Iterate over all possible 3x3 subgrids, top-lefted at (i, j)
    for (int i = 0; i <= R - 3; ++i) {
      for (int j = 0; j <= C - 3; ++j) {
        if (isMagicSquare(grid, i, j)) {
          ++count;
        }
      }
    }
    return count;
  }

private:
  // Helper function to check if a 3x3 grid at top-left (row, col) is magic
  bool isMagicSquare(const vector<vector<int>> &grid, int row, int col) {
    // We use an array of size 10, as values must be 1-9,
    // magic[1..9] marks which numbers have been seen
    bool magic[10];
    std::fill(std::begin(magic), std::end(magic), false);

    // Step 1: Check each number is between 1 and 9, and all are distinct
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int val = grid[row + i][col + j];
        // If the value is out of bounds or duplicated, not magic
        if (val < 1 || val > 9 || magic[val])
          return false;
        magic[val] = true; // Mark this value seen
      }
    }

    // Step 2: All rows, columns, diagonals must sum to 15
    // Check rows
    for (int i = 0; i < 3; ++i) {
      int rowsum = 0;
      for (int j = 0; j < 3; ++j) {
        rowsum += grid[row + i][col + j];
      }
      if (rowsum != 15)
        return false;
    }
    // Check columns
    for (int j = 0; j < 3; ++j) {
      int colsum = 0;
      for (int i = 0; i < 3; ++i) {
        colsum += grid[row + i][col + j];
      }
      if (colsum != 15)
        return false;
    }
    // Check main diagonal
    int diag1 =
        grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
    if (diag1 != 15)
      return false;
    // Check anti-diagonal
    int diag2 =
        grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
    if (diag2 != 15)
      return false;

    // All checks passed
    return true;
  }
};
// @lc code=end
