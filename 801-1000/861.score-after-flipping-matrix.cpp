/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start

#include <cmath> // Include cmath for pow function if needed (but we'll use bit shifting for efficiency).
#include <vector> // Include vector library for 2D matrix representation.

using std::vector;

/*
 * Brief Digested Understanding:
 * ---------------------------------
 * This problem asks us to maximize the sum of an integer for each row,
 * where each row of a matrix is interpreted as a binary number. The only moves
 * allowed are to completely flip (invert all bits in) any row or column as many
 * times as desired. Our job is to pick the right rows/columns to flip so that
 * the sum (when the rows are read as binary numbers) is as large as possible.
 * The main trick is to increase the highest-value bits (the leftmost ones)
 * for as many rows as possible, and then optimize all remaining bits for
 * maximum total.
 *
 * High-Level Summary:
 * ---------------------------------
 * The optimal strategy is:
 *   1. Ensure the leftmost bit of every row is 1 (since this is the "most
 * significant bit" and contributes most to the sum). If a row starts with a 0,
 * flip the entire row.
 *   2. For each column (except the first, which is already all ones now),
 * determine if flipping the column would increase the number of 1s in that
 * column. If so, flip the column. This makes sure that for each column, we
 * maximize the number of 1s.
 *   3. Finally, compute the total sum by converting each row from binary to
 * decimal. All steps can be done in O(m*n) time and O(1) extra space, making
 * this efficient and scalable for the problem's constraints.
 */

// Modularized solution begins here

class Solution {
public:
  // Helper function: flips all bits in a given row.
  void flipRow(vector<int> &row) {
    // Traverse each element in the row and toggle it
    for (int &cell : row) {
      cell ^= 1; // XOR with 1 flips the bit (0->1, 1->0)
    }
  }

  // Helper function: flips all bits in a given column of the grid.
  void flipColumn(vector<vector<int>> &grid, int colIndex) {
    for (auto &row : grid) {
      row[colIndex] ^= 1; // Flip each element in the selected column
    }
  }

  // Helper function: calculates the score of the current grid.
  int calculateScore(const vector<vector<int>> &grid) {
    int totalScore = 0;
    int numCols = grid[0].size();

    // Convert each row from binary to decimal and sum up
    for (const auto &row : grid) {
      int rowValue = 0;
      for (int j = 0; j < numCols; ++j) {
        // Build number by shifting and or-ing in each bit from left to right
        rowValue = (rowValue << 1) | row[j];
      }
      totalScore += rowValue;
    }
    return totalScore;
  }

  int matrixScore(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Step 1: Make sure all rows start with a 1 in the first column (most
    // significant bit)
    for (int i = 0; i < m; ++i) {
      if (grid[i][0] == 0) {
        flipRow(grid[i]);
      }
    }
    // Step 2: For each column (except the first), flip if more rows have 0 than
    // 1
    for (int col = 1; col < n; ++col) {
      int countOnes = 0;
      for (int i = 0; i < m; ++i) {
        if (grid[i][col] == 1) {
          ++countOnes;
        }
      }
      // If 0s are more than 1s, flip column to maximize the number of 1s
      if (countOnes < m - countOnes) {
        flipColumn(grid, col);
      }
    }
    // Step 3: Calculate the final score of the modified grid
    return calculateScore(grid);
  }
};
// @lc code=end
