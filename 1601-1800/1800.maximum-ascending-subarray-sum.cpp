/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        currSum += nums[i];
      } else {
        currSum = nums[i];
      }
      if (currSum > maxSum) {
        maxSum = currSum;
      }
    }
    return maxSum;
  }
};
// @lc code=end
