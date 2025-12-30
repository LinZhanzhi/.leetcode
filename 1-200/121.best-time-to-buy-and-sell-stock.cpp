/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        // Single pass: keep track of minimum price and maximum profit
        for (int i = 1; i < prices.size(); i++) {
            // Update minimum price seen so far
            minPrice = min(minPrice, prices[i]);
            
            // Calculate profit if we sell at current price
            int currentProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currentProfit);
        }
        
        return maxProfit;
    }
};
// @lc code=end

