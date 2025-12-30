/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to determine if there exists a continuous subarray of at
 * least length 2 in the given array `nums` such that the sum of its elements is
 * a multiple of `k`. In other words, we need to find two indices i and j (with
 * j > i) so that the sum of nums[i] + nums[i+1] + ... + nums[j] is divisible by
 * k. The subarray must be at least two elements long.
 *
 * High-Level Summary:
 * ----
 * The key insight is that if two prefix sums have the same remainder when
 * divided by k, then the subarray between them has a sum that is a multiple of
 * k. We use a hash map to store the earliest index where each remainder occurs.
 * As we iterate through the array, we compute the running prefix sum and its
 * remainder modulo k. If we see the same remainder again and the subarray
 * length is at least 2, we return true. This approach is efficient, running in
 * O(n) time and O(k) space.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to check if a good subarray exists
  bool checkSubarraySum(vector<int> &nums, int k) {
    // Helper function to check for a good subarray using prefix sums and a hash
    // map
    return hasGoodSubarray(nums, k);
  }

private:
  // Helper function that implements the prefix sum and remainder logic
  bool hasGoodSubarray(const vector<int> &nums, int k) {
    // Map to store the first index where each remainder occurs
    // Key: remainder, Value: index
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1; // Initialize with remainder 0 at index -1 to handle
                            // subarrays starting at index 0

    int prefixSum = 0; // Running sum of elements

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
      prefixSum += nums[i]; // Update running sum

      // Compute remainder only if k is not zero (k is always >= 1 per
      // constraints)
      int rem = prefixSum % k;

      // If this remainder has been seen before, check the subarray length
      if (remainderIndex.count(rem)) {
        // The previous index where this remainder was seen
        int prevIndex = remainderIndex[rem];
        // Ensure the subarray length is at least 2
        if (i - prevIndex >= 2) {
          return true; // Found a valid subarray
        }
      } else {
        // Store the first occurrence of this remainder
        remainderIndex[rem] = i;
      }
    }
    // No valid subarray found
    return false;
  }
};
// @lc code=end
