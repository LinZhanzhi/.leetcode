/*
 * @lc app=leetcode id=3560 lang=cpp
 *
 * [3560] Find Minimum Log Transportation Cost
 */

// @lc code=start
class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
    auto minCost = [&](int x) -> long long {
      if (x <= k)
        return 0LL;
      return 1LL * k * (x - k);
    };
    if (n > k) {
      return minCost(n);
    }
    return minCost(m);
  }
};
// @lc code=end
