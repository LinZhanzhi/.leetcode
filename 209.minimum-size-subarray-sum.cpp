/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * High-Level Summary:
 * -------------------
 * Problem: Given an array of positive integers `nums` and a positive integer
 * `target`, find the minimal length of a contiguous subarray of which the sum
 * is greater than or equal to `target`. If there is no such subarray, return 0.
 *
 * Approach (O(n log n) Solution):
 * --------------------------------
 * This solution uses prefix sums and binary search to efficiently find the
 * minimal length subarray.
 *
 * - We first compute the prefix sum array, where prefix[i] is the sum of the
 * first i elements of nums. This allows us to compute the sum of any subarray
 * nums[i..j] in O(1) time as prefix[j+1] - prefix[i].
 * - For each possible starting index of the subarray, we use binary search to
 * find the smallest ending index such that the sum from start to end is at
 * least target.
 * - The binary search is performed on the prefix sum array, which is always
 * non-decreasing because all numbers are positive.
 * - This approach is O(n log n) because for each of the n starting indices, we
 * perform a binary search in O(log n) time.
 *
 * Assumptions:
 *   - All elements in nums are positive integers.
 *   - The input array may be empty.
 *
 * Time Complexity: O(n log n), where n is the length of nums.
 * Space Complexity: O(n), due to the prefix sum array.
 *
 * Edge Cases:
 *   - If no subarray meets the requirement, the function returns 0.
 *   - If the array is empty, the function also returns 0.
 */

#include <algorithm> // For std::lower_bound
#include <climits> // For INT_MAX, which represents the initial "infinite" minimum length
#include <vector> // For using the vector container

using namespace std;

// @lc code=start
class Solution {
public:
  // Function to find the minimal length of a contiguous subarray with sum >=
  // target
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size(); // Store the size of the input array for convenience

    // Edge case: If the input array is empty, there can be no subarray, so
    // return 0
    if (n == 0)
      return 0;

    // Step 1: Compute the prefix sum array.
    // prefix[i] will store the sum of the first i elements (nums[0] to
    // nums[i-1]) prefix[0] = 0 (sum of zero elements)
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      // Each prefix[i+1] is the sum of prefix[i] and nums[i]
      prefix[i + 1] = prefix[i] + nums[i];
    }

    int minLen = INT_MAX; // Initialize the minimum length to "infinity" (a very
                          // large number) This will help us track the smallest
                          // valid window found

    // Step 2: For each possible starting index, use binary search to find the
    // minimal ending index
    for (int i = 0; i < n; ++i) {
      // We want to find the smallest j such that prefix[j] - prefix[i] >=
      // target This is equivalent to prefix[j] >= target + prefix[i]
      int required = target + prefix[i];

      // Use lower_bound to find the first position in prefix where the value is
      // >= required lower_bound returns an iterator to the first element not
      // less than required
      auto bound = lower_bound(prefix.begin() + i + 1, prefix.end(), required);

      // If such a position exists, update the minimum length
      if (bound != prefix.end()) {
        // The index of the found position is (bound - prefix.begin())
        int j = bound - prefix.begin();
        // The length of the subarray is (j - i)
        minLen = min(minLen, j - i);
      }
      // If no such position exists, it means no subarray starting at i meets
      // the requirement So we move to the next starting index
    }

    // After checking all possible starting indices, if minLen was never
    // updated, it means no valid subarray was found In that case, return 0 as
    // required by the problem statement
    return minLen == INT_MAX ? 0 : minLen;
  }
};

/*
 * ---------------------------------------------------------------------------
 * Previous O(n) Sliding Window Solution (Commented Out for Reference)
 * ---------------------------------------------------------------------------
 * // This is the optimal O(n) solution using the sliding window technique.
 * // It is commented out here to demonstrate the O(n log n) approach above.
 * int minSubArrayLen(int target, vector<int> &nums) {
 *   int n = nums.size();
 *   int minLen = INT_MAX;
 *   int left = 0, sum = 0;
 *   for (int right = 0; right < n; ++right) {
 *     sum += nums[right];
 *     while (sum >= target) {
 *       minLen = min(minLen, right - left + 1);
 *       sum -= nums[left++];
 *     }
 *   }
 *   return minLen == INT_MAX ? 0 : minLen;
 * }
 */
// @lc code=end
