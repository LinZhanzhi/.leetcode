/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// Brief Digested Understanding:
// ----
// This problem asks us to find the largest "island" in a 2D grid, where each
// island is a group of adjacent land cells (1's) connected only via horizontal
// or vertical paths (not diagonally). "Largest" refers to the number of 1's in
// that connected group. If there are no islands (no 1's), we return 0.
// Effectively, this is a connected-component problem on a matrix, using only
// 4-directional adjacency.

// High-Level Summary:
// ----
// To solve this, we'll scan the grid, and each time we find an unvisited land
// cell (1), we'll use Depth-First Search (DFS) to traverse and "flood" all
// connected land cells, marking them as visited as we go (to avoid counting
// them twice). For each traversal, we'll keep track of the island's area
// (number of cells visited in this group), and update our max-area answer. We
// use recursion for DFS, and mutate the grid directly (set grid[i][j]=0) to
// mark cells as visited to avoid extra space for a separate visited array. This
// gives us O(m*n) time and O(m*n) space in the worst case (when the entire grid
// is land and recursion goes that deep), but space stays low with smaller
// islands. The logic is modularized: grid traversal in the main function, and
// the DFS in a helper function.

#include <algorithm> // For std::max
#include <vector> // To use std::vector for the grid and helper function signatures

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
  /**
   * Main function to find the maximum area of any island in the grid.
   * The function follows these steps:
   *  - Traverse every cell in the grid.
   *  - When a land cell (1) is found, perform DFS from that cell
   *    to "flood" the entire island, counting its area.
   *  - Update the running maximum area after each island.
   *  - Return the largest area found, or 0 if no island exists.
   */
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0; // This will track the largest connected island area found
    int m = grid.size();    // Number of rows in the grid
    int n = grid[0].size(); // Number of columns in the grid

    // Loop through every cell to start DFS from every unvisited land cell.
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // If this cell is land (and, by our visitation method, unvisited):
        if (grid[i][j] == 1) {
          // Use DFS to calculate the total area of this island.
          int area = dfs(grid, i, j, m, n);
          // Update maxArea if we found a bigger island.
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea; // Return the largest area found, or 0 if no land was found
                    // at all.
  }

private:
  /**
   * Helper function: Depth-First Search to traverse all connected land cells
   * from position (i, j), turning them into water (visited) and counting area.
   * Arguments:
   *  - grid: the grid itself (passed by reference for in-place modification)
   *  - i, j: current coordinates in the grid
   *  - m, n: dimensions of the grid for bounds checking
   * Returns:
   *  - The total area (number of cells) in the current island
   */
  int dfs(vector<vector<int>> &grid, int i, int j, int m, int n) {
    // First, check out-of-bounds or if cell isn't land
    if (i < 0 || i >= m || j < 0 || j >= n)
      return 0; // Out of grid
    if (grid[i][j] == 0)
      return 0; // Already visited or water, not part of island

    // We have found a new land cell, so we mark it as visited
    grid[i][j] = 0; // Mark this cell as visited by turning it into water

    int area = 1; // Count this cell

    // Now recursively visit all 4 adjacent cells (up, down, left, right)
    area += dfs(grid, i + 1, j, m, n); // Down
    area += dfs(grid, i - 1, j, m, n); // Up
    area += dfs(grid, i, j + 1, m, n); // Right
    area += dfs(grid, i, j - 1, m, n); // Left

    // Return the total area found from this (i, j) root
    return area;
  }
};
// @lc code=end
