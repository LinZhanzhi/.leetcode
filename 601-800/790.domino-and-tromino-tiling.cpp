/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

/**
 * Brief Digested Understanding:
 * ----
 * This problem is really about counting the number of distinct ways to
 completely fill a 2xN rectangle using only two types of tiles:
 *  - 2x1 dominoes (which can be placed vertically or horizontally)
 *  - "L"-shaped trominoes (which can be rotated to fit in various ways)
 * Each square must be covered, so the challenge is essentially a *tiling
 dynamic programming* problem, with extra care toward considering how the
 tromino can connect rows. Two tilings are treated as different if they have
 even a single border between two cells where tiles touch differently.
 * The core is to figure out, for each length N, how many possibilities there
 are, based on the ways to extend tilings of shorter boards.

 * High-Level Summary:
 * ----
 * We will use dynamic programming (DP) to build up the solution for `n` from
 smaller values.
 * We'll define dp[i] as the number of ways to tile a 2xi board.
 * The recurrence relates dp[i] to dp[i-1] (vertical domino at the end), dp[i-2]
 (two horizontal dominoes at end, or one tromino), and a term using dp[i-3] (to
 account for ways to add an L-tromino).
 * The critical recurrence is: dp[n] = dp[n-1] + dp[n-2] + 2*dp[n-3] + ...,
 * but it can be written more simply as:
 *     dp[n] = 2*dp[n-1] + dp[n-3]
 * We'll precompute all values up to n (since n ≤ 1000, this is efficient).
 * The expected time and space complexity are both O(n).
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
private:
  static const int MOD = 1e9 + 7;

  // Helper function to compute DP for tiling
  int computeNumTilings(int n) {
    // dp[i]: the number of ways to tile a 2xi board
    vector<long long> dp(n + 1, 0);

    // Base cases:
    // dp[0] = 1: One way to fill a 2x0 board (do nothing)
    // dp[1] = 1: Only one vertical domino
    // dp[2] = 2: two vertical dominoes or two horizontal dominoes
    dp[0] = 1;
    if (n >= 1)
      dp[1] = 1;
    if (n >= 2)
      dp[2] = 2;

    // Fill dp[i] for i = 3..n using the recurrence:
    // dp[i] = 2*dp[i-1] + dp[i-3]
    for (int i = 3; i <= n; ++i) {
      // Placing a vertical domino adds dp[i-1] ways
      // Placing two horizontal dominoes adds dp[i-2] ways
      // Placing a tromino (in either orientation) contributes dp[i-3]*2
      // But due to overlapping configurations, the recurrence simplifies to
      // below explain more on overlapping configurations overlapping
      // configurations are when two trominoes are placed in a way that they
      // overlap each other for example, when two trominoes are placed in a way
      // that they overlap each other, they form a 2x2 square this is not
      // allowed in the problem, so we need to subtract the number of ways to
      // place two trominoes in a way that they overlap each other the number of
      // ways to place two trominoes in a way that they overlap each other is
      // dp[i-3] so we need to subtract dp[i-3] from the total number of ways to
      // place two trominoes the number of ways to place two trominoes in a way
      // that they overlap each other is dp[i-3] why not just use dp[i] =
      // dp[i-1] + dp[i-2] + dp[i-3]*2 because when we place a tromino, we need
      // to subtract the number of ways to place two trominoes in a way that
      // they overlap each other so we need to subtract dp[i-3] from the total
      // number of ways to place two trominoes

      dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }
    return static_cast<int>(dp[n]);
  }

public:
  int numTilings(int n) {
    // Validate input (not strictly needed since 1 <= n <= 1000 by constraints)
    if (n < 0)
      return 0;
    // Use helper to compute result
    return computeNumTilings(n);
  }
};
// @lc code=end
