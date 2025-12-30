/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to traverse a 2D matrix in a zigzag diagonal order,
 * starting from the top-left corner. We need to collect all elements by moving
 * along diagonals, alternating the direction (up-right, then down-left, and so
 * on). The traversal should continue until all elements are visited, and the
 * result should be a 1D array of these elements in the order they are visited.
 *
 * High-Level Summary:
 * ----
 * The solution simulates the diagonal traversal by keeping track of the current
 * position (row, col) and the direction of movement. We alternate between
 * moving up-right and down-left. When we hit the matrix boundaries, we adjust
 * the position and switch direction. The algorithm iterates exactly m*n times
 * (where m and n are the matrix dimensions), so each element is visited once.
 *
 * Time Complexity: O(m * n), where m is the number of rows and n is the number
 * of columns. Space Complexity: O(m * n) for the output array.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace for convenience

// @lc code=start
class Solution {
public:
  // Main function to return the diagonal order traversal of the matrix
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    // Get the number of rows (m) and columns (n)
    int m = mat.size();
    int n = mat[0].size();

    // Prepare the result vector with the correct size
    vector<int> result(m * n);

    // Helper function to check if a position is within matrix bounds
    auto inBounds = [&](int row, int col) -> bool {
      return row >= 0 && row < m && col >= 0 && col < n;
    };

    // Initialize the starting position and direction
    int row = 0, col = 0;
    // The direction variable: 1 means moving up-right, -1 means down-left
    int dir = 1;

    // Iterate over all elements in the matrix
    for (int i = 0; i < m * n; ++i) {
      // Place the current element into the result
      result[i] = mat[row][col];

      // Move in the current direction
      if (dir == 1) { // Moving up-right
        // If we're at the last column, move down to the next row and switch
        // direction
        if (col == n - 1) {
          ++row;
          dir = -1;
        }
        // If we're at the first row, move right to the next column and switch
        // direction
        else if (row == 0) {
          ++col;
          dir = -1;
        }
        // Otherwise, move up and to the right
        else {
          --row;
          ++col;
        }
      } else { // dir == -1, moving down-left
        // If we're at the last row, move right to the next column and switch
        // direction
        if (row == m - 1) {
          ++col;
          dir = 1;
        }
        // If we're at the first column, move down to the next row and switch
        // direction
        else if (col == 0) {
          ++row;
          dir = 1;
        }
        // Otherwise, move down and to the left
        else {
          ++row;
          --col;
        }
      }
    }

    // Return the filled result vector
    return result;
  }
};
// @lc code=end
