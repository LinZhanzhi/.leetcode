/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

/*
 * High-Level Summary:
 * -------------------
 * Problem: Given a 2D grid of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically.
 *
 * Approach:
 * - We use Depth-First Search (DFS) to traverse each island.
 * - When we find a '1' (land), we increment our island count and use DFS to
 * mark all connected '1's as visited (by changing them to '0').
 * - This ensures that each island is counted only once.
 *
 * Assumptions:
 * - The grid is a rectangular 2D vector of characters, where each cell is
 * either '1' or '0'.
 * - The input grid may be empty or have empty rows.
 *
 * Time Complexity: O(m * n), where m is the number of rows and n is the number
 * of columns.
 *   - Each cell is visited at most once.
 * Space Complexity: O(m * n) in the worst case due to the recursion stack (if
 * the entire grid is land).
 *   - No extra data structures are used except for the recursion stack.
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  // This helper function performs a Depth-First Search (DFS) starting from cell
  // (i, j). It marks all land cells ('1') connected to (i, j) as visited by
  // changing them to '0'. Parameters:
  //   - grid: The 2D grid representing the map of '1's (land) and '0's (water).
  //   - i, j: The current cell's row and column indices.
  //   - m, n: The total number of rows and columns in the grid.
  void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
    // Base case: If the current cell is out of bounds (i or j is invalid), or
    // if the current cell is not land ('1'), we stop the DFS.
    // This prevents us from visiting water, already visited land, or going
    // outside the grid.
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
      return;
    }

    // Mark the current cell as visited by setting it to '0'.
    // This prevents revisiting the same land cell and ensures each island is
    // counted only once.
    grid[i][j] = '0';

    // Recursively visit all four adjacent cells (up, down, left, right).
    // This explores the entire connected component (island) starting from (i,
    // j).
    dfs(grid, i + 1, j, m, n); // Down
    dfs(grid, i - 1, j, m, n); // Up
    dfs(grid, i, j + 1, m, n); // Right
    dfs(grid, i, j - 1, m, n); // Left
  }

  // Main function to count the number of islands in the grid.
  // Returns the total number of islands found.
  int numIslands(vector<vector<char>> &grid) {
    // Edge case: If the grid is empty or the first row is empty, there are no
    // islands.
    if (grid.empty() || grid[0].empty())
      return 0;

    // m: number of rows in the grid
    int m = grid.size();
    // n: number of columns in the grid
    int n = grid[0].size();

    // count: variable to keep track of the number of islands found
    int count = 0;

    // Iterate over every cell in the grid.
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // If the current cell is land ('1'), it means we've found a new island.
        if (grid[i][j] == '1') {
          // Increment the island count.
          ++count;
          // Use DFS to mark all cells in this island as visited.
          // This ensures we don't count the same island more than once.
          dfs(grid, i, j, m, n);
        }
        // If the cell is '0', it's either water or already visited land, so we
        // skip it.
      }
    }
    // After traversing the entire grid, return the total number of islands
    // found.
    return count;
  }
};
// @lc code=end
