/*
 * @lc app=leetcode id=2706 lang=cpp
 *
 * [2706] Buy Two Chocolates
 */

// @lc code=start
class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    int n = prices.size();
    int min1 = 101, min2 = 101;
    for (int price : prices) {
      if (price < min1) {
        min2 = min1;
        min1 = price;
      } else if (price < min2) {
        min2 = price;
      }
    }
    int total = min1 + min2;
    if (total > money)
      return money;
    return money - total;
  }
};
// @lc code=end
