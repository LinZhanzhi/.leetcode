/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int maxWealth = 0;
    for (const auto &customer : accounts) {
      int wealth = 0;
      for (int money : customer) {
        wealth += money;
      }
      if (wealth > maxWealth) {
        maxWealth = wealth;
      }
    }
    return maxWealth;
  }
};
// @lc code=end
