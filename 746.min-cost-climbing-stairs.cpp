/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <algorithm>
#include <vector>

// The problem can be solved using dynamic programming.
// Let dp[i] be the minimum cost to reach step i (not including the cost of step
// i itself). The cost to step onto the top (step n) is 0, and you can reach it
// from either step n-1 or n-2. The formula is:
//   dp[0] = 0
//   dp[1] = 0
//   dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) for i >= 2
// The answer is dp[n], where n = cost.size().

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size();
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]
    for (int i = 2; i <= n; ++i) {
      int curr = std::min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};
// @lc code=end
