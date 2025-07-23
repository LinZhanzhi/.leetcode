/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    double maxSum = 0, windowSum = 0;
    for (int i = 0; i < k; ++i) {
      windowSum += nums[i];
    }
    maxSum = windowSum;
    for (int i = k; i < nums.size(); ++i) {
      windowSum += nums[i] - nums[i - k];
      if (windowSum > maxSum) {
        maxSum = windowSum;
      }
    }
    return maxSum / k;
  }
};
// @lc code=end
