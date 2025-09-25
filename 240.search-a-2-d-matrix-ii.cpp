/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a 2D matrix where each row is sorted from left to right and each
 * column is sorted from top to bottom. The task is to efficiently determine if
 * a given target value exists anywhere in the matrix. The key insight is that
 * the matrix's sorting properties allow us to eliminate entire rows or columns
 * at each step, rather than searching every element.
 */

/*
 * High-Level Summary:
 * ----
 * The optimal approach is to start searching from the top-right corner of the
 * matrix. At each step:
 *   - If the current value is equal to the target, return true.
 *   - If the current value is greater than the target, move left (decrease
 * column).
 *   - If the current value is less than the target, move down (increase row).
 * This works because moving left decreases values (since rows are sorted), and
 * moving down increases values (since columns are sorted). The algorithm
 * continues until it either finds the target or goes out of bounds.
 *
 * Time Complexity: O(m + n), where m is the number of rows and n is the number
 * of columns. Space Complexity: O(1), as we only use a constant amount of extra
 * space.
 */

#include <vector>  // Include vector to use std::vector for the matrix.
using std::vector; // Bring std::vector into the current namespace for
                   // convenience.

// @lc code=start
class Solution {
public:
  // Function to search for a target value in a 2D sorted matrix.
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // Get the number of rows (m) and columns (n) in the matrix.
    int m = matrix.size();
    if (m == 0)
      return false; // Edge case: empty matrix.
    int n = matrix[0].size();
    if (n == 0)
      return false; // Edge case: empty rows.

    // Start from the top-right corner of the matrix.
    int row = 0;     // Start at the first row.
    int col = n - 1; // Start at the last column.

    // Loop until we go out of bounds.
    while (row < m && col >= 0) {
      int current = matrix[row][col]; // Current value at (row, col).
      if (current == target) {
        // If we find the target, return true.
        return true;
      } else if (current > target) {
        // If current value is greater than target, move left to a smaller
        // value.
        col--;
      } else {
        // If current value is less than target, move down to a larger value.
        row++;
      }
    }
    // If we exit the loop, the target is not in the matrix.
    return false;
  }
};
// @lc code=end
