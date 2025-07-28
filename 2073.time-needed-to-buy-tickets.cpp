/*
 * @lc app=leetcode id=2073 lang=cpp
 *
 * [2073] Time Needed to Buy Tickets
 */

// @lc code=start
class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int time = 0;
    // Iterate through each person in the queue
    for (int i = 0; i < tickets.size(); ++i) {
      if (i <= k) {
        // For people before or at position k, they will buy up to tickets[k]
        // tickets (or less if they have fewer tickets to buy)
        time += min(tickets[i], tickets[k]);
      } else {
        // For people after position k, they will only get a chance to buy
        // tickets[k] - 1 times, because after the k-th person buys their last
        // ticket, the process stops
        time += min(tickets[i], tickets[k] - 1);
      }
    }
    // Return the total time taken for the k-th person to finish buying tickets
    return time;
  }
};
// @lc code=end
