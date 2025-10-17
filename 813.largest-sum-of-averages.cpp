/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// Brief Digested Understanding:
// ----
// The problem is about dividing an array of numbers into at most 'k' contiguous
// groups (subarrays). For each group, we compute its average (sum divided by
// length), and add up all these averages. The goal is to choose where to split
// (partition) so that the sum of these averages is maximized. Each element must
// appear in exactly one group, groups must be contiguous, and the number of
// groups can be less than or equal to k. We must return the maximum total sum
// of averages possible (high precision required).

// High-Level Summary:
// ----
// We solve this problem with dynamic programming (DP).
// Our main idea is: let dp[i][j] be the maximum sum of averages we can get by
// splitting the first i elements (nums[0..i-1]) into j groups. For every
// possible subarray ending at position i, we try all earlier partitions,
// calculating the average for the last group, and recursively determine the
// best result. We use prefix sums for O(1) average computation of any subarray.
// Our DP transition: dp[i][j] = max over p in [j-1, i-1] of { dp[p][j-1] +
// average of nums[p..i-1] }. The final answer is dp[n][k], where n =
// nums.size(). Time complexity: O(n^2 * k) where n is the length of nums. Space
// complexity: O(n*k) for the DP and prefix sum arrays.

#include <numeric> // Needed for std::accumulate
#include <vector>  // Needed for std::vector

using std::vector;

class Solution {
public:
  // Helper function to calculate prefix sums for efficient subarray sum
  // calculation. prefix[i] will be sum of first i elements (nums[0] to
  // nums[i-1]), with prefix[0]=0.
  vector<double> computePrefixSums(const vector<int> &nums) {
    int n = nums.size();
    vector<double> prefix(n + 1, 0.0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    return prefix;
  }

  // Helper function to compute average of nums[left...right] (inclusive) in
  // O(1) time using prefix sums.
  double subarrayAverage(const vector<double> &prefix, int left, int right) {
    // The sum of nums[left...right] is prefix[right+1] - prefix[left].
    // The number of elements is (right - left + 1).
    return (prefix[right + 1] - prefix[left]) / (right - left + 1);
  }

  double largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // Compute prefix sums for fast subarray sum/average queries.
    vector<double> prefix = computePrefixSums(nums);

    // dp[i][j] will represent: maximum score by partitioning first i elements
    // into j groups We need (n+1) rows and (k+1) columns, because we use
    // dp[0][0] as the empty case.
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));

    // Base case: partitioning first i elements into 1 group - sum all and take
    // their average
    for (int i = 1; i <= n; ++i) {
      dp[i][1] = subarrayAverage(prefix, 0, i - 1);
      // Explanation: No split - all elements 0..i-1 in one group
    }

    // Fill DP table for j = 2 to k groups
    for (int groups = 2; groups <= k; ++groups) {
      // For each length of array (i), try possible last split
      for (int i = groups; i <= n; ++i) {
        // To split into 'groups', last group must start after (groups-1)
        // elements Try all possible places to start the last group
        for (int p = groups - 1; p < i; ++p) {
          // dp[p][groups-1]: optimum for first 'p' elements with (groups-1)
          // groups subarrayAverage(prefix, p, i-1): average for last group
          double candidate =
              dp[p][groups - 1] + subarrayAverage(prefix, p, i - 1);
          if (candidate > dp[i][groups]) {
            dp[i][groups] = candidate;
          }
        }
      }
    }

    // The answer is the maximum we can achieve by splitting the whole array
    // into at most k groups.
    double result = 0.0;
    // It's allowed to use fewer than k groups, so check all possibilities.
    for (int groups = 1; groups <= k; ++groups) {
      if (dp[n][groups] > result) {
        result = dp[n][groups];
      }
    }
    return result;
  }
};
// @lc code=end
