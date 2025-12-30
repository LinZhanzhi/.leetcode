/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is: Given a list of coin denominations and a target amount, how
 * many different ways can you combine the coins (using each coin as many times
 * as you want) to make up exactly that amount? The order of coins in a
 * combination does not matter. If it's not possible to make the amount, return
 * 0.
 *
 * High-Level Summary:
 * ----
 * Instead of filling a full DP table (which can cause overflow in some test
 * cases), we use recursion with memoization. We define a function f(i, j) as
 * the number of ways to make up amount j using the first i coins. The
 * recurrence is: for each possible number k (from 0 up to the maximum number of
 * times we can use the i-th coin without exceeding j), sum f(i-1, j -
 * k*coins[i-1]). We use a memoization table to cache results and avoid
 * recomputation. This approach only computes the needed cells, and as
 * guaranteed by the problem, the answer will fit in a 32-bit int.
 *
 * Time Complexity: O(n * amount^2) in the worst case (but often much less in
 * practice due to memoization and pruning). Space Complexity: O(n * amount) for
 * the memoization table.
 */

#include <vector>        // Include vector for using std::vector
using std::vector;       // Bring vector into the current namespace
#include <cstring>       // For memset (optional, if using C-style arrays)
#include <unordered_map> // For memoization with pair key

// @lc code=start
class Solution {
public:
  // Main function to compute the number of combinations to make up 'amount'
  int change(int amount, vector<int> &coins) {
    // Initialize memoization table with -1 (uncomputed)
    int n = coins.size();
    // Use a 2D vector for memoization: memo[i][j] = number of ways to make
    // amount j with first i coins
    memo = vector<vector<int>>(n + 1, vector<int>(amount + 1, -1));
    // Start recursion from using all coins and the full amount
    return countWays(n, amount, coins);
  }

private:
  vector<vector<int>> memo; // Memoization table

  // Helper function: returns number of ways to make up 'amount' using first 'i'
  // coins
  int countWays(int i, int amount, const vector<int> &coins) {
    // Base case: If amount is 0, there is 1 way (use no coins)
    if (amount == 0)
      return 1;
    // Base case: If no coins left or amount is negative, no way to make amount
    if (i == 0 || amount < 0)
      return 0;
    // Check if already computed
    if (memo[i][amount] != -1)
      return memo[i][amount];

    int res = 0;
    int coin = coins[i - 1];
    // Try all possible numbers of current coin (from 0 up to amount/coin)
    for (int k = 0; k * coin <= amount; ++k) {
      // For each k, subtract k*coin from amount and use first (i-1) coins
      res += countWays(i - 1, amount - k * coin, coins);
      // This ensures we do not count permutations, only combinations
    }
    // Store result in memoization table
    memo[i][amount] = res;
    return res;
  }
};
// @lc code=end
