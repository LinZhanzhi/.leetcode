/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to find, between two given integer arrays, the largest
 * contiguous subarray (block of elements in order, no skipping) that appears in
 * both. In other words, we're looking for the longest sequence that shows up in
 * both arrays at (possibly different) places, without gaps. The answer is the
 * length of that longest shared "slice." Both arrays can be up to 1000 in size,
 * so simple brute-force checking of all subarrays would be too slow. The core
 * idea is about recognizing *matching spans* between the arrays, not just
 * individual elements.
 *
 * High-Level Summary:
 * ----
 * To efficiently solve this, we'll use dynamic programming (DP), very similar
 * to the classical "Longest Common Substring" problem (not the less restrictive
 * "Longest Common Subsequence"). We'll create a DP table where dp[i][j] holds
 * the length of the longest matching subarray ending at nums1[i-1] and
 * nums2[j-1]. If nums1[i-1] == nums2[j-1], then dp[i][j] is 1 plus the value
 * from dp[i-1][j-1], extending a previous match; otherwise, it's 0 (no match).
 * We'll update and track the largest value found as we go, which is our answer.
 *
 * - Pattern: Bottom-up DP with a 2D table.
 * - Time Complexity: O(N*M), where N and M are the lengths of nums1 and nums2.
 * - Space: O(N*M) for the table (with further optimization possible, but not
 * required here).
 */

// @lc code=start
#include <algorithm> // For std::max to track maximum value.
#include <vector>    // To use std::vector for nums1, nums2, and DP table.

using std::max;
using std::vector;

class Solution {
public:
  // Public function to compute the maximum length of a shared subarray
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    // Use a modular helper for clarity and breakdown.
    return longestCommonSubarrayDP(nums1, nums2);
  }

private:
  /**
   * Helper function to compute the length of the longest repeated subarray
   * (common contiguous block) between two integer arrays using DP.
   *
   * @param nums1: First input array
   * @param nums2: Second input array
   * @return int: Maximum length of repeated subarray
   */
  int longestCommonSubarrayDP(const vector<int> &nums1,
                              const vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    // dp[i][j] stores the length of the longest matching subarray ending at
    // nums1[i-1] and nums2[j-1]. Need size (n+1)x(m+1) for base case (0).
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0; // Will store the answer as we go

    // Loop over every possible ending index pair in both arrays
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          // If current elements match, extend previous match by one
          dp[i][j] = dp[i - 1][j - 1] + 1;
          // Update maximum found length so far
          maxLen = max(maxLen, dp[i][j]);
        } else {
          // No match at this position, so reset length to 0
          dp[i][j] = 0;
        }
      }
    }
    return maxLen; // Longest shared contiguous subarray length
  }
};
// @lc code=end
