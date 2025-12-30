/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// Brief Digested Understanding:
// ----
// This problem is about simulating a walk through a 2D grid starting from a
// given starting cell, initially facing east. While walking, you need to
// visit every cell in the grid exactly once, moving in a clockwise spiral
// pattern that "peels out" further from the center each cycle. If your
// movement takes you temporarily outside the grid's bounds, you continue
// walking and can re-enter the grid. The main task is to record the order in
// which you visit the actual grid cells.

// High-Level Summary:
// ----
// We'll simulate the spiral by tracking direction and the number of steps to
// take in each direction. The direction sequence repeats every four moves:
// east, south, west, north. After every two turns, the length of the leg of
// the spiral increases by one. We'll loop until we've visited all cells in the
// grid, recording the ones we pass that are in bounds. We'll use vectors for
// the result, direction management, and a simple row/column tracker. The time
// complexity is O(rows*cols), as we must visit every cell exactly once. Space
// complexity is also O(rows*cols) for the output storage.

#include <vector> // Include to use std::vector for flexible arrays.
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function: returns a list of the order in which grid coordinates are
  // visited.
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    // Helper function to check if a position is within grid bounds.
    auto isInBounds = [rows, cols](int r, int c) -> bool {
      return r >= 0 && r < rows && c >= 0 && c < cols;
    };

    // Prepare the output vector with enough size to hold all cell positions.
    vector<vector<int>> result;
    result.reserve(rows * cols); // Avoids reallocating as we push_back.

    // Direction vectors: East, South, West, North (in order).
    // Each represents a (dr, dc) pair: the change in row and column.
    const vector<int> dr = {0, 1, 0, -1}; // Row deltas.
    const vector<int> dc = {1, 0, -1, 0}; // Col deltas.

    int total_cells = rows * cols;
    int r = rStart, c = cStart; // Current position in the spiral.
    int dir = 0;   // Start facing "East", which is direction index 0.
    int steps = 1; // Number of steps to move in current "straight line".

    // Record the starting cell if within bounds.
    if (isInBounds(r, c))
      result.push_back({r, c});

    // Continue until we've added all grid cells to the result.
    while (result.size() < total_cells) {
      // For each of two turns (right angle), repeat the process:
      // this way, after two directions, we increase "steps" by one.
      for (int turn = 0; turn < 2 && result.size() < total_cells; ++turn) {
        // Move in the current direction 'steps' times.
        for (int i = 0; i < steps && result.size() < total_cells; ++i) {
          // Move forward one cell in the current direction.
          r += dr[dir];
          c += dc[dir];
          // If the new position is inside the grid, record it.
          if (isInBounds(r, c)) {
            result.push_back({r, c});
          }
          // Otherwise, keep walking, since the spiral can wander
          // outside the grid and later return inside.
        }
        // After completing steps in this direction, turn right
        // (next direction in our cycle).
        dir = (dir + 1) % 4;
      }
      // After every two direction changes (i.e., a 180-degree turn),
      // increase "steps" by 1 to expand the spiral outward.
      ++steps;
    }

    return result;
  }
};
// @lc code=end
