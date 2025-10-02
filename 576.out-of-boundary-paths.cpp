/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We have a grid, and a ball starts at a given cell. We can move the ball up,
 * down, left, or right, up to a certain number of moves (maxMove). Each time
 * the ball moves out of the grid boundary, it counts as a valid path. The goal
 * is to count all possible ways the ball can move out of the grid boundary in
 * at most maxMove moves, starting from the given position. The answer can be
 * very large, so we return it modulo 10^9 + 7.
 *
 * High-Level Summary:
 * ----
 * The problem is a classic dynamic programming (DP) scenario where we need to
 * count the number of ways to reach an "out of bounds" state from a starting
 * cell, given a limited number of moves. We use memoization (top-down DP) to
 * avoid recalculating the number of paths from the same cell with the same
 * number of moves left. The DP state is defined by (row, col, moves_left). For
 * each move, we try all four directions. If the ball goes out of bounds, we
 * count that as one path. The time complexity is O(m * n * maxMove), and space
 * complexity is also O(m * n * maxMove) due to memoization.
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
  // Define the modulo as required by the problem
  static constexpr int MOD = 1e9 + 7;

  // Helper function for DP with memoization
  int findPathsHelper(int m, int n, int maxMove, int row, int col,
                      vector<vector<vector<int>>> &memo) {
    // If out of bounds, this is a valid path
    if (row < 0 || row >= m || col < 0 || col >= n) {
      return 1;
    }
    // If no moves left and still in bounds, no valid path
    if (maxMove == 0) {
      return 0;
    }
    // If already computed, return the cached result
    if (memo[row][col][maxMove] != -1) {
      return memo[row][col][maxMove];
    }

    // Try all four directions
    int totalPaths = 0;
    // Directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int d = 0; d < 4; ++d) {
      int newRow = row + dirs[d][0];
      int newCol = col + dirs[d][1];
      // Recursively count paths from the new position with one less move
      totalPaths = (totalPaths +
                    findPathsHelper(m, n, maxMove - 1, newRow, newCol, memo)) %
                   MOD;
    }
    // Memoize the result for current state
    memo[row][col][maxMove] = totalPaths;
    return totalPaths;
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // 3D memoization table: m x n x (maxMove+1), initialized to -1 (uncomputed)
    vector<vector<vector<int>>> memo(
        m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
    // Start the DP from the initial position and maxMove
    return findPathsHelper(m, n, maxMove, startRow, startColumn, memo);
  }
};
// @lc code=end
