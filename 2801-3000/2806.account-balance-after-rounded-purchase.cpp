/*
 * @lc app=leetcode id=2806 lang=cpp
 *
 * [2806] Account Balance After Rounded Purchase
 */

// @lc code=start
class Solution {
public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    int roundedAmount = ((purchaseAmount + 5) / 10) * 10;
    return 100 - roundedAmount;
  }
};
// @lc code=end
