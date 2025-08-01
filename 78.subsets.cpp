/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subset;
    function<void(int)> dfs = [&](int idx) {
      if (idx == nums.size()) {
        res.push_back(subset);
        return;
      }
      // Exclude nums[idx]
      dfs(idx + 1);
      // Include nums[idx]
      subset.push_back(nums[idx]);
      dfs(idx + 1);
      subset.pop_back();
    };
    dfs(0);
    return res;
  }
};
// @lc code=end
