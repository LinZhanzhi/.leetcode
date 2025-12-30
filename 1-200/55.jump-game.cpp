/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int farthest = 0;
    for (int i = 0; i < n; ++i) {
      if (i > farthest)
        return false;
      farthest = std::max(farthest, i + nums[i]);
      if (farthest >= n - 1)
        return true;
    }
    return true;
  }
};
// @lc code=end
