/*
 * @lc app=leetcode id=2427 lang=cpp
 *
 * [2427] Number of Common Factors
 */

// @lc code=start
class Solution {
public:
  int commonFactors(int a, int b) {
    int count = 0;
    int limit = std::min(a, b);
    for (int i = 1; i <= limit; ++i) {
      if (a % i == 0 && b % i == 0) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
