/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    function<void(int)> dfs = [&](int start) {
      res.push_back(subset);
      for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1])
          continue;
        subset.push_back(nums[i]);
        dfs(i + 1);
        subset.pop_back();
      }
    };
    dfs(0);
    return res;
  }
};
// @lc code=end
