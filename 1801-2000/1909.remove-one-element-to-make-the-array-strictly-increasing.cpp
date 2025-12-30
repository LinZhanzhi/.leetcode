/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
  bool canBeIncreasing(vector<int> &nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] <= nums[i - 1]) {
        count++;
        if (count > 1)
          return false;
        // Check if removing nums[i-1] or nums[i] can help
        if (i == 1 || nums[i] > nums[i - 2]) {
          // Removing nums[i-1] works
          continue;
        } else if (i + 1 == n || nums[i + 1] > nums[i - 1]) {
          // Removing nums[i] works
          continue;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
