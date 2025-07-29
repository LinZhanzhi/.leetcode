/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
class Solution {
public:
  int maximumCount(vector<int> &nums) {
    // Use binary search to find the count of negative and positive numbers
    // Count of negative numbers: index of first 0 (lower_bound)
    // Count of positive numbers: nums.size() - index of first positive
    // (upper_bound of 0)
    int n = nums.size();
    // Find first index where nums[i] >= 0
    int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    // Find first index where nums[i] > 0
    int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
    return max(neg, pos);
  }
};
// @lc code=end
