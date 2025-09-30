/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given an array of integers, we are to compute a "rotation function" F(k) for
 * each possible rotation k (from 0 to n-1), where F(k) is the sum of each
 * element in the rotated array multiplied by its index. The goal is to find the
 * maximum value among all F(k). The challenge is to do this efficiently, as
 * recalculating F(k) from scratch for each rotation would be too slow for large
 * arrays.
 */

/*
 * High-Level Summary:
 * ----
 * The key insight is to find a relationship between F(k) and F(k-1) so that we
 * can compute each F(k) in O(1) time after computing F(0) in O(n) time.
 * Specifically, F(k) = F(k-1) + sum(nums) - n * nums[n-k], where sum(nums) is
 * the sum of all elements in the array. We first compute F(0) and sum(nums),
 * then iteratively compute each F(k) using the formula, keeping track of the
 * maximum value found. This results in an O(n) time and O(1) space solution.
 */

#include <numeric> // Include numeric for std::accumulate
#include <vector>  // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    // Get the size of the input array
    int n = nums.size();

    // Compute the sum of all elements in nums
    long totalSum = std::accumulate(nums.begin(), nums.end(), 0L);

    // Compute F(0): sum of i * nums[i] for i from 0 to n-1
    long F = 0;
    for (int i = 0; i < n; ++i) {
      F += static_cast<long>(i) * nums[i];
    }

    // Initialize the result with F(0)
    long maxValue = F;

    // Iteratively compute F(k) for k = 1 to n-1 using the derived formula
    // F(k) = F(k-1) + totalSum - n * nums[n - k]
    for (int k = 1; k < n; ++k) {
      // nums[n - k] is the element that moves from the end to the front after
      // rotation
      F = F + totalSum - static_cast<long>(n) * nums[n - k];
      // Update the maximum value found so far
      if (F > maxValue) {
        maxValue = F;
      }
    }

    // Return the maximum value as an int (guaranteed to fit by problem
    // statement)
    return static_cast<int>(maxValue);
  }
};
// @lc code=end
