/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; // skip duplicates for i
      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue; // skip duplicates for j
        int left = j + 1, right = n - 1;
        while (left < right) {
          long long sum =
              (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            ++left;
            --right;
            while (left < right && nums[left] == nums[left - 1])
              ++left; // skip duplicates for left
            while (left < right && nums[right] == nums[right + 1])
              --right; // skip duplicates for right
          } else if (sum < target) {
            ++left;
          } else {
            --right;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
