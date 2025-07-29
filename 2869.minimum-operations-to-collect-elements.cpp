/*
 * @lc app=leetcode id=2869 lang=cpp
 *
 * [2869] Minimum Operations to Collect Elements
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    unordered_set<int> collected;
    int n = nums.size();
    int ops = 0;
    for (int i = n - 1; i >= 0; --i) {
      ++ops;
      if (nums[i] <= k) {
        collected.insert(nums[i]);
        if (collected.size() == k) {
          return ops;
        }
      }
    }
    return ops;
  }
};
// @lc code=end
