/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// Brief Digested Understanding:
// ----
// The core idea of this problem is to find the minimum sum among all possible
// paths that go from the top to the bottom of a square matrix, moving only one
// row down at a time, and only to the same column or its two immediate
// neighbors. That is, at each step you can move directly down, or down-left, or
// down-right. You want the smallest possible sum among all such paths, starting
// at any element in the first row and ending at any element in the last row.

// High-Level Summary:
// ----
// The optimal way to solve this problem is dynamic programming (DP),
// specifically a bottom-up approach where we build up the minimum falling-path
// sums row by row. For each cell, we compute the minimum sum ending at that
// cell by looking at the three possible cells above it (up-left, up, up-right).
// We'll use a DP table (2D vector) to keep track of these minimum sums. This
// approach has O(n^2) time and space complexity, where n is the number of rows.
// For optimization, we could use one row of space, but for clarity we'll use
// the full table. We'll modularize the code with a helper function to safely
// get the minimum of the three relevant values, which ensures we correctly
// handle edge columns.

// Include necessary headers for using vectors and minimum functions.
#include <algorithm> // for std::min
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
  // Main function to compute the minimum falling path sum
  int minFallingPathSum(vector<vector<int>> &matrix) {
    // Get the size of the square matrix
    int n = matrix.size();
    // Edge case: if matrix is empty, return 0 (should not happen due to
    // constraints)
    if (n == 0)
      return 0;

    // dp[i][j] will represent the minimum sum of a falling path ending at cell
    // (i, j)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the first row of dp to be equal to the first row of the
    // matrix, since any falling path must start here.
    for (int j = 0; j < n; ++j) {
      dp[0][j] = matrix[0][j];
    }

    // Helper lambda to get the value above the current cell safely,
    // returning INT_MAX if column is out of bounds.
    auto getAbove = [&](int i, int j) -> int {
      if (j < 0 || j >= n) {
        // Return a large value for out-of-bounds columns, so it is not chosen.
        return INT_MAX;
      }
      return dp[i][j];
    };

    // Loop through all rows starting from the second one
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // For each cell, compute the minimum sum from three allowed positions
        // above
        int minAbove = min({
            getAbove(i - 1, j - 1), // diagonally up-left
            getAbove(i - 1, j),     // directly above
            getAbove(i - 1, j + 1)  // diagonally up-right
        });
        // Update dp table for this cell
        dp[i][j] = matrix[i][j] + minAbove;
      }
    }

    // The answer is the minimum value in the last row,
    // since any path can end at any cell in the last row.
    int result = dp[n - 1][0];
    for (int j = 1; j < n; ++j) {
      result = min(result, dp[n - 1][j]);
    }
    return result;
  }
};
// @lc code=end
