/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to find, given an array of integers, how many different
 * strictly increasing subsequences exist that have the maximum possible length.
 * In other words, among all possible increasing subsequences, how many are as
 * long as the longest one? The answer should count all such subsequences,
 * including those that may overlap in elements or positions.
 *
 * High-Level Summary:
 * ----
 * We'll use dynamic programming to solve this efficiently. For each position in
 * the array, we'll keep track of two things:
 *   1. The length of the longest increasing subsequence ending at that
 * position.
 *   2. The number of such longest subsequences ending at that position.
 * We'll iterate through the array, and for each element, look back at all
 * previous elements to update these two arrays. At the end, we'll find the
 * maximum length and sum up the counts for all positions where the subsequence
 * length equals this maximum. This approach runs in O(n^2) time and O(n) space,
 * which is efficient enough for the given constraints.
 */

#include <algorithm> // Include algorithm for std::max.
#include <vector>    // Include vector for dynamic arrays.

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the number of longest increasing subsequences.
  int findNumberOfLIS(vector<int> &nums) {
    // Edge case: if the array is empty, there are no subsequences.
    if (nums.empty())
      return 0;

    int n = nums.size();
    // dp[i]: length of the longest increasing subsequence ending at index i.
    vector<int> dp(n, 1);
    // count[i]: number of longest increasing subsequences ending at index i.
    vector<int> count(n, 1);

    // Helper function to update dp and count arrays.
    auto updateDPAndCount = [&](int i) {
      // For each previous index j, check if nums[j] < nums[i].
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          // If extending the subsequence at j gives a longer length.
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            count[i] = count[j]; // Start a new count from j.
          }
          // If extending gives the same length, add the number of ways.
          else if (dp[j] + 1 == dp[i]) {
            count[i] += count[j];
          }
        }
      }
    };

    // Fill dp and count arrays for each index.
    for (int i = 0; i < n; ++i) {
      updateDPAndCount(i);
    }

    // Find the length of the longest increasing subsequence.
    int maxLen = *std::max_element(dp.begin(), dp.end());

    // Sum up the counts for all indices where the subsequence length is maxLen.
    int totalCount = 0;
    for (int i = 0; i < n; ++i) {
      if (dp[i] == maxLen) {
        totalCount += count[i];
      }
    }

    return totalCount;
  }
};
// @lc code=end
