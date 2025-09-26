/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of daily stock prices and can buy and sell as many times
 * as we want, but after selling, we must wait one day (cooldown) before buying
 * again. We cannot hold more than one stock at a time. The goal is to maximize
 * profit by choosing the best days to buy and sell, considering the cooldown
 * restriction.
 *
 * High-Level Summary:
 * ----
 * This problem is a variation of the stock trading dynamic programming (DP)
 * problems. We use DP to track the maximum profit at each day for three
 * possible states:
 *   1. Holding a stock (hold)
 *   2. Not holding and in cooldown (cooldown, i.e., just sold)
 *   3. Not holding and not in cooldown (rest)
 *
 * For each day, we update these states based on the previous day's values and
 * the current price. The answer is the maximum profit on the last day when not
 * holding a stock (either in cooldown or rest).
 *
 * Time Complexity: O(n), where n is the number of days (prices.size()).
 * Space Complexity: O(1), since we only need to keep track of the previous
 * day's states.
 */

#include <algorithm> // Include algorithm for std::max
#include <vector>    // Include vector for using std::vector

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // Edge case: If there are no prices or only one day, no transactions can be
    // made.
    if (prices.empty())
      return 0;

    // Initialize the three states for day 0:
    // hold: The max profit if we are holding a stock at the end of day 0 (i.e.,
    // we bought it). cooldown: The max profit if we are in cooldown at the end
    // of day 0 (i.e., we just sold, which is impossible on day 0). rest: The
    // max profit if we are not holding and not in cooldown at the end of day 0.
    int hold = -prices[0]; // We buy on day 0, so profit is -prices[0]
    int cooldown = 0;      // Can't be in cooldown on day 0
    int rest = 0;          // No action taken, profit is 0

    // Iterate through each day, updating the states.
    for (int i = 1; i < prices.size(); ++i) {
      int prev_hold = hold;         // Store previous hold value for calculation
      int prev_cooldown = cooldown; // Store previous cooldown value
      int prev_rest = rest;         // Store previous rest value

      // If we hold a stock today, it means:
      //   - We held it yesterday (do nothing), or
      //   - We bought it today (must have been in rest yesterday)
      hold = max(prev_hold, prev_rest - prices[i]);

      // If we are in cooldown today, it means:
      //   - We sold the stock today (must have held it yesterday)
      cooldown = prev_hold + prices[i];

      // If we are in rest today, it means:
      //   - We were in rest or cooldown yesterday (do nothing)
      rest = max(prev_rest, prev_cooldown);
    }

    // The answer is the maximum profit on the last day when not holding a
    // stock, i.e., either in cooldown or rest state.
    return max(cooldown, rest);
  }
};
// @lc code=end
