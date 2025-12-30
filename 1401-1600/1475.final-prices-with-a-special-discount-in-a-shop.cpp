/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    int n = prices.size();
    vector<int> answer = prices;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (prices[j] <= prices[i]) {
          answer[i] = prices[i] - prices[j];
          break;
        }
      }
    }
    return answer;
  }
};
// @lc code=end
