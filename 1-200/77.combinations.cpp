/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> comb;

    function<void(int, int)> backtrack = [&](int start, int k_left) {
      if (k_left == 0) {
        res.push_back(comb);
        return;
      }
      for (int i = start; i <= n - k_left + 1; ++i) {
        comb.push_back(i);
        backtrack(i + 1, k_left - 1);
        comb.pop_back();
      }
    };

    backtrack(1, k);
    return res;
  }
};
// @lc code=end
