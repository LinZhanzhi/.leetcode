/*
 * @lc app=leetcode id=3375 lang=cpp
 *
 * [3375] Minimum Operations to Make Array Values Equal to K
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_set<int> unique_nums(nums.begin(), nums.end());
    nums.assign(unique_nums.begin(), unique_nums.end());
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[0] < k)
      return -1;
    if (nums[0] == k)
      return nums.size() - 1;
    return nums.size();
  }
};
// @lc code=end
