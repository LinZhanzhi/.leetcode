/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to efficiently answer multiple queries for the sum of
 * elements within any rectangular subregion of a given 2D matrix. Each query
 * specifies the top-left and bottom-right corners of the rectangle, and we must
 * return the sum of all elements inside that rectangle. The key challenge is to
 * make each query very fast (constant time), even if the matrix is large or
 * there are many queries.
 *
 * High-Level Summary:
 * ----
 * To achieve O(1) query time, we precompute a 2D prefix sum matrix during
 * construction. The prefix sum at (i, j) represents the sum of all elements in
 * the rectangle from (0, 0) to (i-1, j-1) in the original matrix. For any
 * query, we use the inclusion- exclusion principle to compute the sum of any
 * subrectangle using at most four prefix sum lookups and some
 * additions/subtractions. This approach requires O(mn) time and space for
 * preprocessing, but each sumRegion query is O(1).
 */

#include <vector> // Include vector for 2D matrix and prefix sum storage
using std::vector;

// @lc code=start
class NumMatrix {
private:
  // 2D prefix sum matrix, where prefix[i][j] is the sum of elements in the
  // rectangle from (0,0) to (i-1, j-1) in the original matrix.
  vector<vector<int>> prefix;

public:
  // Constructor: Precompute the 2D prefix sum matrix.
  NumMatrix(vector<vector<int>> &matrix) {
    // Get the number of rows (m) and columns (n) in the input matrix.
    int m = matrix.size();
    int n = m > 0 ? matrix[0].size() : 0;

    // Initialize the prefix sum matrix with (m+1) x (n+1) size, filled with 0s.
    // The extra row and column (at index 0) simplify boundary conditions.
    prefix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    // Compute prefix sums for each cell.
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // The prefix sum at (i, j) is:
        //   - prefix[i-1][j]   : sum above
        //   - prefix[i][j-1]   : sum to the left
        //   - -prefix[i-1][j-1]: remove double-counted top-left area
        //   - +matrix[i-1][j-1]: add current cell
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                       prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
    // After this, prefix[i][j] gives the sum of the rectangle from (0,0) to
    // (i-1,j-1).
  }

  // Return the sum of the rectangle from (row1, col1) to (row2, col2),
  // inclusive.
  int sumRegion(int row1, int col1, int row2, int col2) {
    // Since prefix is 1-based, add 1 to all indices.
    int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;

    // Use the inclusion-exclusion principle:
    // Total = prefix[r2][c2]
    //       - prefix[r1-1][c2]   (remove area above)
    //       - prefix[r2][c1-1]   (remove area to the left)
    //       + prefix[r1-1][c1-1] (add back overlap)
    return prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] +
           prefix[r1 - 1][c1 - 1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
