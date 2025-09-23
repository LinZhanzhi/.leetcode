/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given a 2D grid of '0's and '1's, we want to find the area of the largest
 * square (with all sides equal) that contains only '1's. The area is the number
 * of cells in that square (side length squared). We need to efficiently check
 * all possible squares in the matrix and find the largest one made up entirely
 * of '1's.
 *
 * High-Level Summary:
 * ----
 * We use dynamic programming (DP) to solve this problem efficiently. For each
 * cell, we keep track of the size of the largest square whose bottom-right
 * corner is at that cell. If the cell is '1', its value is 1 plus the minimum
 * of the values from the cell above, to the left, and diagonally up-left. We
 * iterate through the matrix, updating our DP table, and keep track of the
 * largest square found.
 *
 * Time Complexity: O(m * n), where m and n are the matrix dimensions.
 * Space Complexity: O(m * n) for the DP table, but can be optimized to O(n).
 */

#include <algorithm> // Include algorithm for std::min and std::max
#include <vector>    // Include vector for 2D matrix representation

using std::vector;

// @lc code=start
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    // Edge case: if the matrix is empty, return 0
    if (matrix.empty() || matrix[0].empty())
      return 0;

    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns
    int maxSide = 0; // To keep track of the largest square's side length

    // Create a DP table with the same dimensions as the matrix
    // dp[i][j] will store the side length of the largest square ending at (i,
    // j)
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Iterate through each cell in the matrix
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // Only process if the current cell is '1'
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0) {
            // If we're in the first row or first column, the largest square is
            // 1
            dp[i][j] = 1;
          } else {
            // Otherwise, we use the dynamic programming recurrence:
            // For cell (i, j) that is '1', the largest square ending here
            // depends on the largest squares ending at its top (i-1, j),
            // left (i, j-1), and top-left diagonal (i-1, j-1) neighbors.
            // The reason we take the minimum of these three is because a square
            // can only be extended if ALL three neighbors can also form a
            // square of at least that size. If any neighbor has a smaller
            // square, it means that a larger square cannot be formed at (i, j)
            // without including a '0' somewhere in the area. By taking the
            // minimum, we ensure that all cells in the potential square
            // (including the new row and column) are '1'. We add 1 to account
            // for the current cell.
            dp[i][j] =
                1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
          }
          // Update the maximum square side length found so far
          maxSide = std::max(maxSide, dp[i][j]);
        }
        // If the cell is '0', dp[i][j] remains 0 (no square can end here)
      }
    }

    // The area of the largest square is side length squared
    return maxSide * maxSide;
  }
};
// @lc code=end
