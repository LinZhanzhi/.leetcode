/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given a matrix of 0s and 1s, for each cell, we want to find out how far it is
 * (in steps, moving up/down/left/right) to the nearest 0. If a cell is already
 * 0, its distance is 0. If it's a 1, we want the minimum number of moves to
 * reach any 0 in the matrix.
 *
 * High-Level Summary:
 * ----
 * The most efficient way to solve this is to use a multi-source Breadth-First
 * Search (BFS). We treat all 0s as starting points and expand outwards,
 * updating the distance for each 1 as we reach it for the first time. This
 * ensures that each cell gets the shortest possible distance to a 0. The
 * algorithm runs in O(m*n) time and uses O(m*n) space, where m and n are the
 * matrix dimensions.
 */

#include <queue>   // For std::queue
#include <utility> // For std::pair
#include <vector>  // For std::vector

using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
  // Main function to update the matrix with distances to the nearest 0
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();    // Number of rows
    int n = mat[0].size(); // Number of columns

    // Result matrix initialized with -1 for 1s, and 0 for 0s
    vector<vector<int>> dist(m, vector<int>(n, -1));

    // Queue for BFS: stores pairs of (row, col)
    queue<pair<int, int>> q;

    // Step 1: Initialize the queue with all 0s and set their distance to 0
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          dist[i][j] = 0; // Distance to nearest 0 is 0
          q.push({i, j}); // Enqueue all 0s as BFS sources
        }
        // 1s remain -1 for now, to be updated during BFS
      }
    }

    // Directions for moving up, down, left, right
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Step 2: BFS from all 0s simultaneously
    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();

      // Explore all 4 neighbors
      for (const auto &dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        // Check if neighbor is within bounds and not visited yet
        if (isValid(newRow, newCol, m, n) && dist[newRow][newCol] == -1) {
          // Update distance: 1 more than current cell
          dist[newRow][newCol] = dist[row][col] + 1;
          // Enqueue the neighbor for further BFS
          q.push({newRow, newCol});
        }
      }
    }

    // Return the matrix with updated distances
    return dist;
  }

private:
  // Helper function to check if a cell is within matrix bounds
  bool isValid(int row, int col, int m, int n) {
    // Returns true if (row, col) is inside the matrix
    return row >= 0 && row < m && col >= 0 && col < n;
  }
};
// @lc code=end
