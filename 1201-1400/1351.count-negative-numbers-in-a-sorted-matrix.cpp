/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    // The matrix is sorted in non-increasing order both row-wise and
    // column-wise. We can start from the top-right corner and move left/down:
    // - If the current element is negative, all elements below it in the same
    // column are also negative.
    //   So, we add (m - row) to the count and move left.
    // - If the current element is non-negative, move down to the next row.
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
      if (grid[row][col] < 0) {
        // All elements in this column from current row to bottom are negative
        count += (m - row);
        col--;
      } else {
        // Move to the next row
        row++;
      }
    }
    return count;
  }
};
// @lc code=end
