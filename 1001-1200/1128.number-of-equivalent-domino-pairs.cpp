/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    // INSERT_YOUR_CODE
    unordered_map<int, int> count;
    int res = 0;
    for (const auto &d : dominoes) {
      // Normalize the domino so that [a, b] and [b, a] are treated the same
      int key = d[0] < d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
      res += count[key];
      count[key]++;
    }
    return res;
  }
};
// @lc code=end
