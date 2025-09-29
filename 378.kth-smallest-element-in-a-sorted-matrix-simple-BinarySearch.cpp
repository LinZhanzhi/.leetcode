/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a square matrix where each row and each column is sorted in
 * ascending order. The task is to find the kth smallest element in the entire
 * matrix (not just unique elements). The challenge is to do this efficiently,
 * especially in terms of memory usage, since the matrix can be large.
 *
 * High-Level Summary:
 * ----
 * The optimal approach leverages the sorted property of the matrix. We use
 * binary search on the value range (from the smallest to the largest element in
 * the matrix). For each candidate value (mid), we count how many elements in
 * the matrix are less than or equal to mid. If that count is less than k, we
 * know the kth smallest is larger; otherwise, it's smaller or equal. This
 * approach avoids storing all elements and achieves better than O(n^2) memory.
 * The counting step is O(n) per binary search iteration, leading to an overall
 * time complexity of O(n * log(max-min)), where max and min are the largest and
 * smallest elements in the matrix. Space complexity is O(1) (ignoring input).
 */

#include <algorithm> // For std::min and std::max
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the kth smallest element in the matrix
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size(); // The matrix is n x n

    // The smallest possible value is at the top-left, the largest at the
    // bottom-right
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];

    // Binary search over the value range in the matrix
    while (left < right) {
      int mid = left + (right - left) / 2; // Avoid overflow

      // Count how many elements are less than or equal to mid
      int count = countLessEqual(matrix, mid);

      if (count < k) {
        // If there are fewer than k elements <= mid, the kth smallest is
        // larger
        left = mid + 1;
      } else {
        // Otherwise, the kth smallest is <= mid
        right = mid;
      }
    }
    // When left == right, we've found the kth smallest element
    return left;
  }

private:
  // Helper function to count elements <= target in the matrix
  int countLessEqual(const vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int count = 0;
    int row = n - 1; // Start from the bottom-left corner
    int col = 0;

    // Move up or right depending on the value at (row, col)
    while (row >= 0 && col < n) {
      if (matrix[row][col] <= target) {
        // All elements in this row above (row, col) are also <= target
        count += row + 1;
        col++; // Move to the next column
      } else {
        // Current element is too large, move up to a smaller value
        row--;
      }
    }
    return count;
  }
};
// @lc code=end