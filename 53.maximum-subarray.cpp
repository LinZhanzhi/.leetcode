/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // prevsum[i] = sum(nums[0, i]), inclusive
    // sum(nums[i, j]) = prevsum[j] - prevsum[i-1]
    // for a specific j, we want to find an i in [0, j] such that sum(nums[i,
    // j]) is maximized we can use a prefix sum array to find this
  }
};
// @lc code=end
