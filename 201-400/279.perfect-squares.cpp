/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to find the minimum number of perfect square numbers (like 1, 4,
 * 9, 16, etc.) that add up to a given integer n. For example, for n = 12, the
 * answer is 3 because 12 = 4 + 4 + 4 (three perfect squares). We want the
 * smallest count of such squares whose sum is exactly n.
 *
 * High-Level Summary:
 * ----
 * This problem is a classic example of the "integer break" or "coin change"
 * dynamic programming (DP) pattern. We use a DP array where dp[i] represents
 * the least number of perfect squares that sum to i. For each number from 1 to
 * n, we try subtracting all possible perfect squares less than or equal to i,
 * and update dp[i] as the minimum of its current value and dp[i - square] + 1.
 * This ensures that for every i, we find the optimal (minimum) number of
 * perfect squares needed.
 *
 * Time Complexity: O(n * sqrt(n)), since for each i from 1 to n, we check up to
 * sqrt(i) perfect squares. Space Complexity: O(n), for the DP array.
 */

// @lc code=start
#include <algorithm> // Include algorithm for std::min
#include <vector>    // Include vector for dynamic programming array

class Solution {
public:
  int numSquares(int n) {
    // dp[i] will hold the minimum number of perfect squares that sum to i
    std::vector<int> dp(
        n + 1, INT_MAX); // Initialize all values to a large number (infinity)
    dp[0] = 0;           // Base case: 0 can be formed with 0 numbers

    // Loop through all numbers from 1 to n to fill dp[]
    for (int i = 1; i <= n; ++i) {
      // For each i, try every perfect square less than or equal to i
      for (int j = 1; j * j <= i; ++j) {
        int square = j * j; // Compute the perfect square
        // If we can reach i by adding this square to a previous sum,
        // update dp[i] if this gives a smaller count
        dp[i] = std::min(dp[i], dp[i - square] + 1);
      }
    }
    // The answer for n is now stored in dp[n]
    return dp[n];
  }
};
// @lc code=end
