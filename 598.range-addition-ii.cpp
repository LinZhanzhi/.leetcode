/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    if (ops.empty())
      return m * n;
    int min_a = m, min_b = n;
    for (const auto &op : ops) {
      min_a = std::min(min_a, op[0]);
      min_b = std::min(min_b, op[1]);
    }
    return min_a * min_b;
  }
};
// @lc code=end
