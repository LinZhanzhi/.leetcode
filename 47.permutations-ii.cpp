/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    vector<int> path;

    function<void()> backtrack = [&]() {
      if (path.size() == nums.size()) {
        res.push_back(path);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (used[i])
          continue;
        // this is to enforce relative order of same value elements, so that
        // there will not be duplicates
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
          continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack();
        path.pop_back();
        used[i] = false;
      }
    };

    backtrack();
    return res;
  }
};
// @lc code=end
