/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// Brief Digested Understanding:
// ----
// This problem is about finding the minimum number of water cells (0's) to flip
// to land (1's) to connect two distinct islands on a grid. Each island is made
// up of 1's, and water separates them. We want to “build a bridge” by flipping
// some water cells, and find the smallest such bridge (minimum flips) that
// connects the islands.

// High-Level Summary:
// ----
// To solve this, we'll first find one island and mark all its land cells. Then,
// we'll perform a breadth-first search (BFS) from all the cells of this island,
// expanding step by step in all directions over 0's (water), counting each
// layer of expansion as one "flip." The first time we reach the other island,
// the number of layers (steps) we've expanded is our answer. We use BFS for the
// shortest-path guarantee, and DFS for island marking. The main data structures
// are the grid itself, a queue for BFS, and direction arrays. Time complexity
// is O(N^2), as each cell is seen at most twice. Space complexity is also
// O(N^2) due to grid and BFS queue.

#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
  // The main function to solve the problem.
  int shortestBridge(vector<vector<int>> &grid) {
    int n = grid.size(); // Dimensions of the grid.
    // Directions: up, right, down, left.
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pair<int, int>>
        bfs_queue;      // Queue for BFS expansion from the first island.
    bool found = false; // Flag to indicate if first island is found.

    // Helper function: Depth-First Search to collect all cells of first island
    // and mark them.
    auto dfs = [&](int r, int c, auto &&dfs_ref) -> void {
      // Check grid bounds and make sure we are on a land cell.
      if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
        return;
      // Mark the cell as part of island 2 (arbitrary, just avoid confusing
      // between original 1's)
      grid[r][c] = 2;
      // Add to BFS queue because BFS will start from all these edge cells.
      bfs_queue.emplace(r, c);
      // Visit all 4 neighbors recursively.
      for (const auto &dir : directions) {
        int nr = r + dir.first, nc = c + dir.second;
        dfs_ref(nr, nc, dfs_ref);
      }
    };

    // Step 1: Find the first land cell to start marking the first island.
    for (int r = 0; r < n && !found; ++r) {
      for (int c = 0; c < n && !found; ++c) {
        if (grid[r][c] == 1) {
          // Mark the entire first island and put its positions into the BFS
          // queue
          dfs(r, c, dfs);
          found = true;
        }
      }
    }

    // Step 2: BFS to expand "bridge" from the first island and find the
    // shortest path to the second island.
    int steps = 0;
    while (!bfs_queue.empty()) {
      int qsize = bfs_queue.size();
      // Each level of BFS represents flipping one more water cell.
      for (int i = 0; i < qsize; ++i) {
        auto [r, c] = bfs_queue.front();
        bfs_queue.pop();
        for (const auto &dir : directions) {
          int nr = r + dir.first, nc = c + dir.second;
          // Skip out-of-bounds coordinates.
          if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;
          // If we find the other island, return the number of flips (steps).
          if (grid[nr][nc] == 1)
            return steps;
          // If this is water and unvisited, mark it and expand into it.
          if (grid[nr][nc] == 0) {
            grid[nr][nc] = 2; // Mark as visited to avoid cycles/revisiting.
            bfs_queue.emplace(nr, nc); // Add to queue for next BFS layer.
          }
          // If grid[nr][nc] == 2, it was already visited—do nothing.
        }
      }
      ++steps; // Increase the number of flips needed as we go to next layer.
    }

    // Problem guarantees there are two islands, so we should always return in
    // the loop. But in case something goes wrong, return -1.
    return -1;
  }
};
// @lc code=end
