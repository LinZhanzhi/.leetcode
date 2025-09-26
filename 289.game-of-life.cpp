/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The Game of Life is a simulation where each cell in a 2D grid is either alive
 * (1) or dead (0). The next state of each cell depends on the number of live
 * neighbors it has, following four simple rules:
 * - Live cells with fewer than 2 or more than 3 live neighbors die.
 * - Live cells with 2 or 3 live neighbors stay alive.
 * - Dead cells with exactly 3 live neighbors become alive.
 * All updates must happen simultaneously, so we can't update cells one by one
 * and use their new values for neighbors.
 *
 * High-Level Summary:
 * ----
 * To solve this in-place (without extra space), we encode both the current and
 * next state in each cell using bit manipulation.
 * - The least significant bit (LSB) of each cell stores the current state (0 or
 * 1).
 * - The second bit will store the next state.
 * We first compute the next state for every cell and store it in the second
 * bit. Then, we update the board by shifting each cell right by one bit to make
 * the next state the current state. This approach uses O(1) extra space and
 * O(m*n) time, where m and n are the board's dimensions.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    // Get the number of rows (m) and columns (n) in the board
    int m = board.size();
    int n = board[0].size();

    // Directions for the 8 neighbors (horizontal, vertical, diagonal)
    // Each pair (dx, dy) represents a direction to a neighbor
    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    // First pass: compute the next state for each cell and encode it in the 2nd
    // bit
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int liveNeighbors = 0; // Count of live neighbors

        // Check all 8 neighbors
        for (int d = 0; d < 8; ++d) {
          int ni = i + dirs[d][0];
          int nj = j + dirs[d][1];
          // Check if neighbor is within bounds
          if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            // Only consider the current state (LSB) of the neighbor
            liveNeighbors += board[ni][nj] & 1;
          }
        }

        // Apply the Game of Life rules:
        // - If the cell is currently alive (LSB is 1)
        if (board[i][j] & 1) {
          // Cell stays alive if it has 2 or 3 live neighbors
          if (liveNeighbors == 2 || liveNeighbors == 3) {
            board[i][j] |= 2; // Set the 2nd bit to 1 (next state: alive)
          }
          // Otherwise, cell dies (2nd bit remains 0)
        } else {
          // If the cell is currently dead and has exactly 3 live neighbors, it
          // becomes alive
          if (liveNeighbors == 3) {
            board[i][j] |= 2; // Set the 2nd bit to 1 (next state: alive)
          }
          // Otherwise, cell stays dead (2nd bit remains 0)
        }
      }
    }

    // Second pass: update the board to the next state by shifting right
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // The next state is stored in the 2nd bit, so shift right to make it
        // the current state
        board[i][j] >>= 1;
      }
    }
  }
};
// @lc code=end
