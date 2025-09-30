/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// Brief, Digested Understanding:
//
// The problem asks us to find all grid cells in a matrix where water can flow
// to both the Pacific and Atlantic oceans. Water can flow from a cell to its
// neighboring cells (up, down, left, right) if the neighbor's height is less
// than or equal to the current cell's height. The Pacific Ocean touches the
// left and top edges, and the Atlantic touches the right and bottom edges. We
// need to return all coordinates from which water can reach both oceans by
// following the flow rules.
//
// High-Level Summary:
//
// The key insight is to reverse the flow: instead of simulating water flowing
// from every cell to the oceans (which is inefficient), we simulate water
// "coming in" from the oceans and see which cells can be reached by each ocean.
// We perform two separate traversals (using DFS or BFS) starting from the
// Pacific and Atlantic edges, marking all cells reachable from each ocean. The
// answer is the intersection of the two sets of reachable cells. Time
// complexity is O(m*n) since each cell is visited at most twice (once for each
// ocean). Space complexity is O(m*n) for the visited matrices and the result.
//
// The code below uses DFS for traversal and includes detailed comments for
// clarity.

#include <vector> // Include vector for 2D grid and result storage
using std::vector;

class Solution {
public:
  // Main function to find all coordinates where water can flow to both oceans
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    // Get the dimensions of the grid
    int m = heights.size();
    if (m == 0)
      return {}; // Edge case: empty grid
    int n = heights[0].size();

    // Create two m x n boolean matrices to track reachability from each ocean
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // Lambda function for DFS traversal
    // It marks all cells reachable from the current cell (r, c) for a given
    // ocean
    auto dfs = [&](int r, int c, vector<vector<bool>> &visited,
                   auto &&dfs_ref) -> void {
      visited[r][c] = true; // Mark current cell as visited for this ocean

      // Directions: up, down, left, right
      static const int dr[4] = {-1, 1, 0, 0};
      static const int dc[4] = {0, 0, -1, 1};

      // Explore all four directions
      for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        // Check if neighbor is within bounds
        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
          continue;
        // Only move to neighbor if:
        // 1. It hasn't been visited for this ocean
        // 2. Its height is >= current cell's height (water can flow from ocean
        // up to this cell)
        if (!visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
          dfs_ref(nr, nc, visited, dfs_ref);
        }
      }
    };

    // Start DFS from all cells adjacent to the Pacific Ocean (top row and left
    // column)
    for (int i = 0; i < m; ++i) {
      dfs(i, 0, pacific, dfs);      // Left edge (Pacific)
      dfs(i, n - 1, atlantic, dfs); // Right edge (Atlantic)
    }
    for (int j = 0; j < n; ++j) {
      dfs(0, j, pacific, dfs);      // Top edge (Pacific)
      dfs(m - 1, j, atlantic, dfs); // Bottom edge (Atlantic)
    }

    // Collect all cells that can reach both oceans
    vector<vector<int>> result;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        // If cell is reachable from both oceans, add to result
        if (pacific[r][c] && atlantic[r][c]) {
          result.push_back({r, c});
        }
      }
    }
    return result;
  }
};
// @lc code=end
