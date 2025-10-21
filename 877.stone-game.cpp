/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// Brief Digested Understanding:
// -----
// In this problem, two players, Alice and Bob, take turns choosing either the
// leftmost or rightmost pile from a row of stone piles. Each pile has a certain
// number of stones, and both players want to maximize their total stones. The
// number of piles is even and the total number of stones is odd, so one player
// must win. The task is to determine if Alice, who always starts first, is
// guaranteed to win if both players play perfectly (optimally). At its core,
// this is about understanding if the first player in this game has a forced
// win, given the initial configuration and rule constraints.

// High-Level Summary:
// -----
// There are two ways to solve this: using a dynamic programming approach which
// models both players' decisions, or by recognizing that with an even number of
// piles and both players playing optimally, Alice can always win. This is
// because Alice can always select piles in such a way (either all even-indexed
// or all odd-indexed) that allows her to collect at least half (and because the
// total is odd, more than half) of the total stones. Therefore, we can
// confidently return true for all valid inputs without any DP calculation. For
// learning purposes, we'll also show a DP helper structure, but the solution
// can be optimized to simply return true in O(1) time and space, since Alice
// always has a winning strategy under these constraints.

// Include missing vector library
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to determine if Alice can always win
  bool stoneGame(vector<int> &piles) {
    // Since there are an even number of piles, Alice can always choose
    // either even- or odd-indexed piles and guarantee a win.
    // See explanation above. This is a mathematical guarantee for
    // this specific setup, so we simply return true.
    return true;
  }

  // (Optional for teaching)
  // If you want to see a DP approach that works in general cases,
  // you can use the code below as educational:
  /*
  // Helper function using DP to calculate optimal play (for education).
  bool stoneGameDP(vector<int>& piles) {
      int n = piles.size();
      // dp[i][j]: max stones more the current player can get than the other
  player from piles i to j std::vector<std::vector<int>> dp(n,
  std::vector<int>(n, 0)); for (int i = 0; i < n; ++i) { dp[i][i] = piles[i]; //
  Base case: only one pile, take it
      }
      // Fill the DP table for ranges of increasing length
      for (int len = 2; len <= n; ++len) {
          for (int i = 0; i <= n - len; ++i) {
              int j = i + len - 1;
              // Choose left or right, subtracting what opponent can do next
              dp[i][j] = std::max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
          }
      }
      // If result is positive, Alice can win
      return dp[0][n-1] > 0;
  }
  */
};
// @lc code=end
