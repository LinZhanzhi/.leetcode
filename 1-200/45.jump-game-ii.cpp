/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int jumps = 0, currEnd = 0, farthest = 0;
    for (int i = 0; i < n - 1; ++i) {
      farthest = max(farthest, i + nums[i]);
      if (i == currEnd) {
        ++jumps;
        currEnd = farthest;
      }
    }
    return jumps;
  }
};
// @lc code=end
