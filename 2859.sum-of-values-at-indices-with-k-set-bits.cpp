/*
 * @lc app=leetcode id=2859 lang=cpp
 *
 * [2859] Sum of Values at Indices With K Set Bits
 */

// @lc code=start
class Solution {
public:
  int sumIndicesWithKSetBits(vector<int> &nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int setBits = __builtin_popcount(i);
      if (setBits == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};
// @lc code=end
