/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int total = 0;
    for (int num : nums) {
      total += num;
    }
    int leftSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (leftSum == total - leftSum - nums[i]) {
        return i;
      }
      leftSum += nums[i];
    }
    return -1;
  }
};
// @lc code=end
