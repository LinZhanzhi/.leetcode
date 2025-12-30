/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is about finding the minimum amount of money you need to
 * guarantee a win in a number guessing game, where each wrong guess costs you
 * the value of your guess. The goal is to minimize your maximum possible loss,
 * no matter which number between 1 and n is picked. This is a classic "minimax"
 * problem: you want to minimize your worst-case cost.
 *
 * High-Level Summary:
 * ----
 * We use dynamic programming to solve this problem. For every possible range
 * [l, r], we compute the minimum cost needed to guarantee a win. For each
 * possible guess x in [l, r], the cost is x plus the maximum cost of the two
 * resulting subranges ([l, x-1] and [x+1, r]), since the worst case is always
 * possible. We fill a DP table bottom-up, considering all subranges, and return
 * the answer for [1, n]. The time complexity is O(n^3) and space complexity is
 * O(n^2).
 */

// @lc code=start
class Solution {
public:
  int getMoneyAmount(int n) {
    // dp[l][r] will store the minimum cost to guarantee a win for numbers in
    // [l, r] We use n+2 to avoid index issues (since we may access dp[x+1][r]
    // and dp[l][x-1])
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // We build the DP table for all possible lengths of ranges
    // len is the length of the current range
    for (int len = 2; len <= n; ++len) {
      // l is the left boundary of the range
      for (int l = 1; l <= n - len + 1; ++l) {
        int r = l + len - 1; // r is the right boundary
        dp[l][r] = INT_MAX;  // Initialize with a large value

        // Try every possible first guess x in [l, r]
        for (int x = l; x <= r; ++x) {
          // If we guess x, the cost is x plus the worst-case cost of the two
          // subranges If x == l, left subrange is empty, so cost is dp[x+1][r]
          // If x == r, right subrange is empty, so cost is dp[l][x-1]
          // Otherwise, take the max of the two subranges
          int cost = x + max((x - 1 >= l ? dp[l][x - 1] : 0),
                             (x + 1 <= r ? dp[x + 1][r] : 0));
          // We want the minimum among all possible first guesses
          dp[l][r] = min(dp[l][r], cost);
        }
      }
    }

    // The answer for the full range [1, n]
    return dp[1][n];
  }
};
// @lc code=end
