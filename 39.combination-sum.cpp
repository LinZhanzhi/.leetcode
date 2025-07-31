/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    function<void(int, int)> dfs = [&](int start, int remain) {
      if (remain == 0) {
        res.push_back(comb);
        return;
      }
      for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > remain)
          continue;
        comb.push_back(candidates[i]);
        dfs(i, remain - candidates[i]);
        comb.pop_back();
      }
    };
    dfs(0, target);
    return res;
  }
};
// @lc code=end
