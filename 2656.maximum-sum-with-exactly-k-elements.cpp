/*
 * @lc app=leetcode id=2656 lang=cpp
 *
 * [2656] Maximum Sum With Exactly K Elements
 */

// @lc code=start
class Solution {
public:
  int maximizeSum(vector<int> &nums, int k) {
    int max_num = *max_element(nums.begin(), nums.end());
    // The maximum sum is max_num + (max_num+1) + ... + (max_num+k-1)
    // This is an arithmetic progression: sum = k*max_num + k*(k-1)/2
    return k * max_num + (k * (k - 1)) / 2;
  }
};
// @lc code=end
