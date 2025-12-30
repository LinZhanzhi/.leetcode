/*
 * @lc app=leetcode id=2733 lang=cpp
 *
 * [2733] Neither Minimum nor Maximum
 */

// @lc code=start
class Solution {
public:
  int findNonMinOrMax(vector<int> &nums) {
    if (nums.size() < 3)
      return -1;
    int mn = nums[0], mx = nums[0];
    for (int n : nums) {
      if (n < mn)
        mn = n;
      if (n > mx)
        mx = n;
    }
    for (int n : nums) {
      if (n != mn && n != mx)
        return n;
    }
    return -1;
  }
};
// @lc code=end
