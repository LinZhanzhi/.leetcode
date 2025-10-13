/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start

#include <algorithm> // For std::max
#include <vector>    // Include the vector header to use std::vector for prices.

using std::vector;

//
// Brief Digested Understanding:
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
// This problem is about maximizing your profit from buying and selling a stock
// over time (given daily prices), but for every round-trip transaction
// (buy+sell), you must pay a fixed fee. You can buy and sell multiple times,
// but can't hold more than one stock at a time (must sell before you buy
// again). The goal is to decide on which days to buy/sell (with the fee in
// mind) to get the most money overall.
//
// High-Level Summary:
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
// We'll use a dynamic programming approach to track two key states for each
// day:
//   1. The maximum profit if we do NOT hold any stock at the end of the day
//   (cash in hand).
//   2. The maximum profit if we DO hold a stock at the end of the day.
//
// On each day, for each state, we can decide whether to buy, sell, or do
// nothing. The transition will account for the transaction fee only when a sale
// happens. We'll use two variables to store and update these states efficiently
// as we iterate through the prices. This solution runs in O(N) time and O(1)
// space, where N is the number of days, because we only need to remember the
// last-day's states.
//
// This modular version provides a main function and clear helper methods for
// updates.
//

class Solution {
public:
  // Main function to calculate maximum profit with transaction fee
  int maxProfit(vector<int> &prices, int fee) {
    // Edge case: If there are no prices or only one, profit is zero (can't
    // sell)
    if (prices.empty())
      return 0;

    // State 1: profit with no stock in hand ("cash" on hand at the end of day)
    int cash = 0;
    // State 2: profit with stock in hand (i.e., bought it before or today)
    int hold = -prices[0];

    // Iterate over each day's price, starting from day 1 (as day 0 is our init
    // state)
    for (size_t i = 1; i < prices.size(); ++i) {
      // First, store previous day's states for clarity
      int prevCash = cash;
      int prevHold = hold;

      // Update cash: either we did nothing (keep prev cash), or sell today
      // If we sell today: we get price[i] (current price), minus transaction
      // fee, and add the profit we had when holding a stock yesterday
      cash = std::max(prevCash, prevHold + prices[i] - fee);

      // Update hold: either we did nothing (keep prev hold), or buy today
      // If we buy today: subtract current price from our cash state
      hold = std::max(prevHold, prevCash - prices[i]);
    }

    // At the end, we want to have no stock in hand (cannot sell after timeline
    // ends) So return cash, which is max profit ending without holding any
    // stock
    return cash;
  }
};

// @lc code=end
