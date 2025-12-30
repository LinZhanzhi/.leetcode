/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// Brief, Digested Understanding:
//
// The problem is to count the number of ways to assign '+' or '-' signs to each
// number in the input array so that the resulting sum equals a given target
// value. For each number, we can either add or subtract it, and we want to
// count all possible assignments that achieve the target sum. The key is to
// efficiently enumerate all possible sums that can be formed by the sequence of
// choices.
//
// High-Level Summary:
//
// We use a bottom-up dynamic programming (DP) approach. Let dp[i][j] represent
// the number of ways to reach sum (j - 1000) using the first i numbers (since
// possible sums range from -1000 to 1000, we shift by 1000 to use non-negative
// indices). The DP table is filled iteratively: for each number, and for each
// possible sum, we update the number of ways to reach new sums by adding or
// subtracting the current number. The base case is dp[0][1000] = 1 (one way to
// reach sum 0 with zero numbers). The answer is dp[n][target+1000] if target is
// in the valid range. Time complexity is O(N*S), where N is the number of
// elements and S is the range of possible sums (2001). Space complexity is also
// O(N*S). The code is modularized: the main function handles the DP table setup
// and update logic, and a helper function is used for safe index checking.

#include <vector> // For std::vector

using std::vector;

class Solution {
public:
  // Main function: returns the number of ways to assign '+' and '-' to reach
  // target
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    // The possible sum range is [-1000, 1000], so we shift by 1000 to use [0,
    // 2000]
    const int OFFSET = 1000;
    const int MAX_SUM = 2000;

    // dp[i][j]: number of ways to reach sum (j - OFFSET) using first i numbers
    // We use n+1 rows (for 0 to n numbers), and MAX_SUM+1 columns (for all
    // possible sums)
    vector<vector<int>> dp(n + 1, vector<int>(MAX_SUM + 1, 0));

    // Base case: one way to reach sum 0 with zero numbers
    dp[0][OFFSET] = 1;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
      int num = nums[i - 1]; // Current number (1-based dp, 0-based nums)
      for (int sum = 0; sum <= MAX_SUM; ++sum) {
        // If there are ways to reach this sum with i-1 numbers
        if (dp[i - 1][sum] != 0) {
          // Option 1: Add num (shifted index)
          int addIdx = sum + num;
          if (addIdx >= 0 && addIdx <= MAX_SUM) {
            dp[i][addIdx] += dp[i - 1][sum];
          }
          // Option 2: Subtract num (shifted index)
          int subIdx = sum - num;
          if (subIdx >= 0 && subIdx <= MAX_SUM) {
            dp[i][subIdx] += dp[i - 1][sum];
          }
        }
      }
    }

    // The answer is the number of ways to reach (target + OFFSET) using all n
    // numbers If target is out of range, there are 0 ways
    if (target < -OFFSET || target > OFFSET) {
      return 0;
    }
    return dp[n][target + OFFSET];
  }
};
// @lc code=end
