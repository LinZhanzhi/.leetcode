/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    // We use two arrays to count how many times each row and each column is
    // incremented.
    vector<int> row(m, 0), col(n, 0);

    // For each index pair, increment the corresponding row and column counters.
    for (const auto &idx : indices) {
      row[idx[0]]++;
      col[idx[1]]++;
    }

    // Count how many rows and columns have been incremented an odd number of
    // times.
    int oddRows = 0, oddCols = 0;
    for (int i = 0; i < m; ++i) {
      if (row[i] % 2 == 1)
        oddRows++;
    }
    for (int j = 0; j < n; ++j) {
      if (col[j] % 2 == 1)
        oddCols++;
    }

    /*
      Explanation:
      - Each cell (i, j) in the matrix is incremented row[i] + col[j] times.
      - The value at (i, j) is odd if and only if row[i] + col[j] is odd.
      - This happens if row[i] is odd and col[j] is even, or row[i] is even and
      col[j] is odd.
      - So, the total number of odd cells is:
          (number of odd rows) * (number of even columns) +
          (number of even rows) * (number of odd columns)
        where:
          number of even columns = n - oddCols
          number of even rows = m - oddRows
    */
    return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
  }
};
// @lc code=end
