/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks: Given a set of coin denominations and a target amount,
 * what is the minimum number of coins needed to make up that amount? If it's
 * not possible, return -1. You can use each coin as many times as you want.
 * This is a classic "minimum coin change" problem, which is a type of
 * unbounded knapsack problem.
 *
 * High-Level Summary:
 * ----
 * We use dynamic programming (DP) to solve this problem efficiently. We create
 * a DP array where dp[i] represents the minimum number of coins needed to make
 * up amount i. We initialize dp[0] = 0 (zero coins needed for amount 0), and
 * all other dp[i] to a large value (e.g., amount+1, which is impossible).
 * For each amount from 1 to the target, we try every coin and update dp[i] if
 * using that coin results in a smaller number of coins. The answer is
 * dp[amount] if it's not impossible; otherwise, return -1. Time Complexity:
 * O(amount * n), where n is the number of coins. Space Complexity: O(amount),
 * for the DP array.
 */

#include <algorithm> // Include algorithm for std::min
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // Create a DP array of size (amount + 1), initialized to a large value.
    // dp[i] will hold the minimum number of coins needed for amount i.
    vector<int> dp(amount + 1, amount + 1); // amount+1 is used as "infinity"
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    // Loop through all amounts from 1 to amount
    for (int i = 1; i <= amount; ++i) {
      // Try every coin denomination
      for (int coin : coins) {
        if (i - coin >= 0) {
          // If it's possible to use this coin, update dp[i]
          // We take the minimum between the current dp[i] and
          // dp[i - coin] + 1 (using this coin)
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    // If dp[amount] is still greater than amount, it means it's impossible
    // to make up that amount with the given coins
    return dp[amount] > amount ? -1 : dp[amount];
  }
};
// @lc code=end
