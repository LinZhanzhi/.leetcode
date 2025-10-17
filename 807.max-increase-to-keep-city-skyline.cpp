/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// Brief Digested Understanding:
// The core idea of this problem is to determine, for each building in a city
// grid, the maximal height it can be increased to without altering how the city
// looks from any direction—specifically, the outer "skyline" when viewed from
// the left (west), right (east), top (north), and bottom (south). You may
// increase each building's height independently. The only restriction:
// post-increase, from any side, the highest building in each row/column
// (skyline) must not change from its original state. So, the challenge is to
// find, across the whole grid, the maximum sum by which you can increase
// heights at each block, while keeping these skyline profiles unchanged.

// High-Level Summary:
// The main approach involves two steps:
// 1. For every row, find its maximum value (the west/east skyline); for every
// column, find its maximum
//    value (the north/south skyline).
// 2. Iterate through each cell in the grid. For cell (i, j), its height can be
// increased up to the
//    minimum of its current row max and column max—any higher would raise its
//    corresponding skyline. The difference between this "allowed" max and its
//    current height is the increase for that cell. Sum up all these differences
//    for the final result.
// We use O(n^2) time and space (where n is grid size), which is acceptable due
// to problem constraints (n <= 50), utilizing vectors for max lookups and
// iteration. Modular helper functions clarify each step.

// @lc code=start
#include <algorithm> // Needed for std::max and std::min
#include <vector>    // Needed for std::vector

using std::vector;

class Solution {
private:
  // Helper function to calculate maximum value in each row of the grid.
  vector<int> getRowMaxima(const vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> rowMax(n, 0);
    // Iterate over each row and find the maximum in that row.
    for (int i = 0; i < n; ++i) {
      rowMax[i] = *std::max_element(grid[i].begin(), grid[i].end());
    }
    return rowMax;
  }

  // Helper function to calculate maximum value in each column of the grid.
  vector<int> getColMaxima(const vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> colMax(n, 0);
    // Iterate over each column and find the maximum for each column.
    for (int j = 0; j < n; ++j) {
      int m = 0;
      for (int i = 0; i < n; ++i) {
        // Update maximum if a larger value is found in the column.
        m = std::max(m, grid[i][j]);
      }
      colMax[j] = m;
    }
    return colMax;
  }

  // Helper function computes the sum total of increases allowed per cell.
  int computeTotalIncrease(const vector<vector<int>> &grid,
                           const vector<int> &rowMax,
                           const vector<int> &colMax) {
    int n = grid.size();
    int sum = 0;
    // For each cell, compute possible increase and accumulate.
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // The new height must not exceed the lower of row max or col max.
        int allowed = std::min(rowMax[i], colMax[j]);
        // The increase is the allowed limit minus the current height, but can't
        // be negative.
        int increase = allowed - grid[i][j];
        if (increase > 0) {
          sum += increase;
        }
      }
    }
    return sum;
  }

public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    // Step 1: Get the max height for every row (for west/east skyline)
    vector<int> rowMax = getRowMaxima(grid);

    // Step 2: Get the max height for every column (for north/south skyline)
    vector<int> colMax = getColMaxima(grid);

    // Step 3: Calculate and return the total possible increase
    return computeTotalIncrease(grid, rowMax, colMax);
  }
};
// @lc code=end
