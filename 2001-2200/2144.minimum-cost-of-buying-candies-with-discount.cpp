/*
 * @lc app=leetcode id=2144 lang=cpp
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start
class Solution {
public:
  int minimumCost(vector<int> &cost) {
    sort(cost.rbegin(), cost.rend());
    int total = 0;
    for (int i = 0; i < cost.size(); ++i) {
      // For every group of 3, skip the 3rd candy (i % 3 == 2)
      if (i % 3 != 2) {
        total += cost[i];
      }
    }
    return total;
  }
};
// @lc code=end
