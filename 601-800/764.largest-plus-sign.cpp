/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// Brief Digested Understanding:
// ----
// The essence of this problem is to find the largest "plus sign" made up only
// of 1's in a grid that is otherwise full of 1's but with some 0's (mines)
// inserted at given positions. A plus sign has a center and four equal-length
// arms—up, down, left, and right. The longest possible such plus sign is what
// we want (measured by the maximum equal arm length from a center cell). The
// grid is large, so our solution must be efficient, not brute-force. For any
// cell, its "order" of plus sign is defined by the minimum number of
// consecutive 1's (including itself) available in each of the four axis
// directions from that cell (clipped by mines).
//
// High-Level Summary:
// ----
// We'll model the grid and keep track, for each cell, of how many "1-blocks"
// extend in each direction from it (left, right, up, down), stopping at any
// mine (0). We can precompute these in four passes over the grid. For each
// cell, the order of the largest plus centered there is the minimum among these
// four values. We compute and record this for the whole grid, and return the
// global maximum order found.
// - Data structures: 2D vectors for grid modeling, a vector or set for mines.
// - Approach: Dynamic programming (DP) by accumulating values in four passes.
// - Time complexity: O(n^2) since each pass visits each cell.
// - Space complexity: O(n^2) for storage of DP or arm-length values for each
// direction.

#include <algorithm>     // Needed for std::min and std::max
#include <unordered_set> // Needed for fast lookup of mines
#include <vector>        // Needed for std::vector

using std::max;
using std::min;
using std::unordered_set;
using std::vector;

class Solution {
public:
  int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    // Helper function to encode (i, j) as a unique integer for set lookup
    auto encode = [n](int i, int j) { return i * n + j; };

    // Step 1: Build a set for constant-time lookup to check if a cell is a mine
    // (0)
    unordered_set<int> mineSet;
    for (const auto &mine : mines) {
      int i = mine[0];
      int j = mine[1];
      // Store (i, j) as a single integer in the set
      mineSet.insert(encode(i, j));
    }

    // Step 2: Create a 2D DP table where dp[i][j] will hold the maximum
    // possible order of a plus sign centered at grid cell (i, j)
    vector<vector<int>> dp(
        n, vector<int>(n, n)); // Initialize with n (max possible order)

    // Four passes to count continuous 1's in each direction

    // LEFT to RIGHT pass
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (mineSet.count(encode(i, j))) {
          count = 0; // Reset arm if it's a mine
        } else {
          count += 1;
        }
        dp[i][j] = min(dp[i][j], count); // Store minimum count so far
      }
    }

    // RIGHT to LEFT pass
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (mineSet.count(encode(i, j))) {
          count = 0;
        } else {
          count += 1;
        }
        dp[i][j] = min(dp[i][j], count);
      }
    }

    // TOP to BOTTOM pass
    for (int j = 0; j < n; ++j) {
      int count = 0;
      for (int i = 0; i < n; ++i) {
        if (mineSet.count(encode(i, j))) {
          count = 0;
        } else {
          count += 1;
        }
        dp[i][j] = min(dp[i][j], count);
      }
    }

    // BOTTOM to TOP pass
    for (int j = 0; j < n; ++j) {
      int count = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (mineSet.count(encode(i, j))) {
          count = 0;
        } else {
          count += 1;
        }
        dp[i][j] = min(dp[i][j], count);
      }
    }

    // Step 3: Find the largest value in dp, which is the answer (the max order
    // of plus sign)
    int largestOrder = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        // dp[i][j] contains the order of largest plus sign centered here
        largestOrder = max(largestOrder, dp[i][j]);
      }
    }
    return largestOrder;
  }
};
// @lc code=end
