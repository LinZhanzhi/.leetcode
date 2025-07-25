/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> res(nums.size());
    res[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      res[i] = res[i - 1] + nums[i];
    }
    return res;
  }
};
// @lc code=end
