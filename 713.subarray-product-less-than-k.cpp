/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to count how many contiguous subarrays (slices of the
 * input array where elements are next to each other) have a product of all
 * their elements strictly less than a given value k. The problem is centered
 * around efficiently checking ranges in the array to see if their
 * multiplication result stays below k. The naive approach of checking every
 * possible subarray would be too slow, so we want to use an optimized solution,
 * given the array can be quite large. An important edge case is when k ≤ 1,
 * where no subarray can meet the requirement (since elements are ≥ 1).
 *
 * High-Level Summary:
 * ----
 * We'll use the sliding window (two pointer) technique. The window [left,
 * right] is the current range such that the product of its elements is less
 * than k.
 * - Expand the window to the right as long as the product stays under k.
 * - If the product reaches or exceeds k, move the left pointer forward and
 * divide out elements from the product until the product goes below k again.
 * - For every new right index, the window size gives the number of new
 * qualifying subarrays ending at that position.
 *
 * Time Complexity: O(n), where n is the number of elements in nums. Each
 * pointer moves forward at most n times. Space Complexity: O(1) beyond the
 * input and output, since we only store a running product and indices.
 */

/*
 * We must #include the vector library for C++.
 */
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // Handle cases where k is less than or equal to 1.
    // In this scenario, there is no valid subarray since every number is at
    // least 1.
    if (k <= 1)
      return 0;

    // Helper function to efficiently count subarrays using sliding window
    return countSlidingWindow(nums, k);
  }

private:
  /**
   * Helper function: Counts the number of contiguous subarrays whose product is
   * less than k.
   *
   * @param nums: vector<int> - input array of positive integers
   * @param k: int - product threshold
   * @return int - number of subarrays with product less than k
   */
  int countSlidingWindow(const vector<int> &nums, int k) {
    int prod = 1;  // Holds the current product of window elements
    int left = 0;  // Left pointer of the window
    int count = 0; // Total number of valid subarrays

    // We use a right pointer to iterate through all elements as the window's
    // end
    for (int right = 0; right < nums.size(); ++right) {
      // Multiply the next element to extend the window
      prod *= nums[right];

      // If product is no longer less than k, shrink window from the left
      // until product is again less than k
      while (prod >= k && left <= right) {
        // Remove nums[left] from the product
        prod /= nums[left];
        // Move the left pointer forward (shrink window)
        left++;
      }

      // At this point, every subarray ending at index 'right' and starting
      // from 'left' to 'right' is valid (product < k), so add their count
      // (number of subarrays is (right - left + 1))
      count += right - left + 1;
    }
    return count;
  }
};
// @lc code=end
