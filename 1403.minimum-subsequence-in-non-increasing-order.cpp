/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
  vector<int> minSubsequence(vector<int> &nums) {
    vector<int> res;
    int total = 0;
    for (int n : nums)
      total += n;
    sort(nums.begin(), nums.end(), greater<int>());
    int curr = 0;
    for (int i = 0; i < nums.size(); ++i) {
      curr += nums[i];
      res.push_back(nums[i]);
      if (curr > total - curr)
        break;
    }
    return res;
  }
};
// @lc code=end
