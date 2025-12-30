/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> comb;
    sort(candidates.begin(), candidates.end());
    function<void(int, int)> backtrack = [&](int start, int target) {
      if (target == 0) {
        res.push_back(comb);
        return;
      }
      for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1])
          continue; // skip duplicates
        if (candidates[i] > target)
          break;
        comb.push_back(candidates[i]);
        backtrack(i + 1, target - candidates[i]);
        comb.pop_back();
      }
    };
    backtrack(0, target);
    return res;
  }
};
// @lc code=end
