/*
 * @lc app=leetcode id=3065 lang=cpp
 *
 * [3065] Minimum Operations to Exceed Threshold Value I
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int ops = 0;
    for (int num : nums) {
      if (num < k)
        ops++;
    }
    return ops;
  }
};
// @lc code=end
