/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int maxVal = -1, secondMax = -1, maxIdx = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > maxVal) {
        secondMax = maxVal;
        maxVal = nums[i];
        maxIdx = i;
      } else if (nums[i] > secondMax) {
        secondMax = nums[i];
      }
    }
    if (maxVal >= 2 * secondMax) {
      return maxIdx;
    }
    return -1;
  }
};
// @lc code=end
