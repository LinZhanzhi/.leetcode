/*
 * @lc app=leetcode id=2917 lang=cpp
 *
 * [2917] Find the K-or of an Array
 */

// @lc code=start
class Solution {
public:
  int findKOr(vector<int> &nums, int k) {
    int result = 0;
    // We need to check each bit position (up to 31, since nums[i] < 2^31)
    for (int bit = 0; bit < 31; ++bit) {
      int count = 0;
      for (int num : nums) {
        if ((num >> bit) & 1) {
          ++count;
        }
      }
      if (count >= k) {
        result |= (1 << bit);
      }
    }
    return result;
  }
};
// @lc code=end
