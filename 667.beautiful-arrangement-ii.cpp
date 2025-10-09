/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// Brief Digested Understanding:
// ----
// This problem is about constructing a permutation of numbers from 1 to n such
// that the absolute differences between consecutive elements yield exactly k
// distinct values. The challenge is to arrange the numbers so that the
// difference sequence is as diverse as required (k distinct values), but not
// more. For k=1, the array is just a sequence (all differences are 1). For
// k=n-1, the array alternates between the smallest and largest available
// numbers to maximize the differences.
//
// High-Level Summary:
// ----
// The optimal approach is to alternate between the smallest and largest
// available numbers for the first k+1 positions, which guarantees k distinct
// differences. After that, the rest of the numbers are filled in order, which
// does not introduce any new differences. This method is efficient and avoids
// unnecessary memory usage by building the result in-place. The algorithm runs
// in O(n) time and uses O(n) space for the output array, which is required by
// the problem. No extra data structures are needed, and the approach is
// memory-efficient.

#include <vector> // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to construct the required array
  vector<int> constructArray(int n, int k) {
    // Result vector to store the permutation
    vector<int> result;
    result.reserve(n); // Reserve space to avoid reallocations

    // Helper function to fill the first k+1 elements in a zigzag pattern
    auto fillZigZag = [&](int k) {
      int left = 1;      // Start pointer (smallest available number)
      int right = k + 1; // End pointer (largest available for zigzag)
      // Alternate between left and right to create k distinct differences
      while (left <= right) {
        if (left == right) {
          // If pointers meet, add the last remaining number
          result.push_back(left);
        } else {
          // Add from left, then from right, to maximize the difference
          result.push_back(left++);
          result.push_back(right--);
        }
      }
    };

    // Step 1: Fill the first k+1 elements to ensure k distinct differences
    fillZigZag(k);

    // Step 2: Fill the rest of the array in increasing order
    // These will only introduce repeated differences (all 1s)
    for (int i = k + 2; i <= n; ++i) {
      result.push_back(i);
    }

    // Return the constructed array
    return result;
  }
};
// @lc code=end
