/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to count how many contiguous subarrays in a given integer
 * array sum up exactly to a target value k. A subarray is any sequence of
 * consecutive elements from the array (it must not be empty). The challenge is
 * to efficiently count all such subarrays, even when the array is large and
 * contains negative numbers.
 *
 * High-Level Summary:
 * ----
 * The optimal solution uses a prefix sum and a hash map to track how many times
 * each prefix sum has occurred. As we iterate through the array, we keep a
 * running sum (prefix sum) of elements so far. For each position, we check if
 * there is a previous prefix sum such that the difference between the current
 * prefix sum and that previous sum is exactly k. If so, it means the subarray
 * between those two positions sums to k. We use a hash map to store the count
 * of each prefix sum seen so far, allowing us to check and update in O(1) time.
 * This approach runs in O(n) time and uses O(n) space, where n is the length of
 * the array.
 */

#include <unordered_map> // For std::unordered_map to store prefix sums
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to count subarrays whose sum equals k
  int subarraySum(vector<int> &nums, int k) {
    // Helper function to count subarrays using prefix sums and a hash map
    return countSubarraysWithSumK(nums, k);
  }

private:
  // Helper function that encapsulates the prefix sum and hash map logic
  int countSubarraysWithSumK(const vector<int> &nums, int k) {
    unordered_map<int, int> prefixSumCount; // Maps prefix sum to its frequency
    prefixSumCount[0] =
        1;              // Initialize with sum 0 occurring once (empty prefix)
    int currentSum = 0; // Running prefix sum
    int count = 0;      // Number of subarrays found

    // Iterate through the array, updating the running sum and checking for
    // valid subarrays
    for (int i = 0; i < nums.size(); ++i) {
      currentSum += nums[i]; // Update the running sum with the current element

      // Check if there is a prefix sum that, when subtracted from currentSum,
      // equals k If so, all subarrays ending at index i with that prefix sum
      // will sum to k
      if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
        count += prefixSumCount[currentSum - k];
      }

      // Record the current prefix sum in the map for future subarrays
      prefixSumCount[currentSum] += 1;
    }

    // Return the total count of subarrays found
    return count;
  }
};
// @lc code=end
