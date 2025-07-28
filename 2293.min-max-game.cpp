/*
 * @lc app=leetcode id=2293 lang=cpp
 *
 * [2293] Min Max Game
 */

// @lc code=start
class Solution {
public:
  int minMaxGame(vector<int> &nums) {
    while (nums.size() > 1) {
      vector<int> newNums(nums.size() / 2);
      for (int i = 0; i < newNums.size(); ++i) {
        if (i % 2 == 0) {
          newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
        } else {
          newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
      }
      nums = newNums;
    }
    return nums[0];
  }
};
// @lc code=end
