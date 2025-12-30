/*
 * @lc app=leetcode id=2465 lang=cpp
 *
 * [2465] Number of Distinct Averages
 */

// @lc code=start
class Solution {
public:
  int distinctAverages(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    unordered_set<int> sums;
    int n = nums.size();
    for (int i = 0; i < n / 2; ++i) {
      int sum = nums[i] + nums[n - 1 - i];
      sums.insert(sum);
    }
    return sums.size();
  }
};
// @lc code=end
