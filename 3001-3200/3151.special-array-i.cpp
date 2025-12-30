/*
 * @lc app=leetcode id=3151 lang=cpp
 *
 * [3151] Special Array I
 */

// @lc code=start
class Solution {
public:
  bool isArraySpecial(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      if ((nums[i] % 2) == (nums[i - 1] % 2)) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
