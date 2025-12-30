/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// Brief Digested Understanding:
// ----
// The core of this problem is to find the largest sum of a non-empty subarray,
// but the twist is that the array is "circular". That is, subarrays may wrap
// from the end back to the start, but - crucially - each index is used at most
// once in a given subarray. The challenge combines standard max-subarray
// (Kadane's algorithm) with the circular case, and you need to consider both
// the typical "linear" sum, and possible "wraparound" scenarios.

// High-Level Summary:
// ----
// We solve this by computing two possible answers:
//   1. The maximum subarray sum in the normal (non-circular) way (using
//   Kadane's algorithm).
//   2. The maximum subarray sum that wraps around: this is the total sum of the
//   array minus the minimum subarray sum (since removing the minimum contiguous
//   subarray gives the maximal wraparound).
// Take the maximum of these two. One detail: when all numbers are negative, the
// wraparound trick (total - min) yields zero, which is invalid (require at
// least one element); thus, in this case we use the plain Kadane's. Time
// complexity is O(n), space is O(1) extra (modulo input).

#include <algorithm> // To use std::max and std::min
#include <numeric>   // To use std::accumulate for getting the total sum
#include <vector>    // To use std::vector for the input array

using std::vector;

class Solution {
public:
  // Main function to return the maximum sum of a non-empty subarray in circular
  // manner
  int maxSubarraySumCircular(vector<int> &nums) {
    // Helper: returns the max sum of any subarray (standard Kadane's)
    auto maxSubarraySum = [](const vector<int> &arr) -> int {
      int currentMax = arr[0]; // Store the max sum ending at current index
      int globalMax = arr[0];  // Store the overall max found so far
      for (size_t i = 1; i < arr.size(); ++i) {
        // For each element, either extend previous subarray or start new
        currentMax = std::max(arr[i], currentMax + arr[i]);
        // Track the largest sum seen
        globalMax = std::max(globalMax, currentMax);
      }
      return globalMax;
    };

    // Helper: returns the min sum of any subarray (Kadane's flipped)
    auto minSubarraySum = [](const vector<int> &arr) -> int {
      int currentMin = arr[0]; // Store the min sum ending at current index
      int globalMin = arr[0];  // Store the overall min found so far
      for (size_t i = 1; i < arr.size(); ++i) {
        // Either extend or start a new min subarray
        currentMin = std::min(arr[i], currentMin + arr[i]);
        globalMin = std::min(globalMin, currentMin);
      }
      return globalMin;
    };

    int totalSum =
        std::accumulate(nums.begin(), nums.end(), 0); // Sum of all elements

    int maxLinear =
        maxSubarraySum(nums); // Max sum in linear (non-circular) fashion
    int minLinear =
        minSubarraySum(nums); // Min sum in linear (for wraparound calculation)

    // If all elements are negative, maxLinear handles it. In this case,
    // totalSum == minLinear. The wraparound case is zero, which is NOT
    // permitted (as result must be non-empty).
    if (maxLinear < 0) {
      // All numbers are negative; no wraparound gives >0 sum, so return maximal
      // single-element subarray
      return maxLinear;
    }

    // Max result is either the max linear subarray sum or the wraparound
    // subarray sum (totalSum - min subarray), whichever is greater
    return std::max(maxLinear, totalSum - minLinear);
  }
};
// @lc code=end
