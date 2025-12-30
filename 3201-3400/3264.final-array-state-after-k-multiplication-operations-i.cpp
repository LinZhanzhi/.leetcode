/*
 * @lc app=leetcode id=3264 lang=cpp
 *
 * [3264] Final Array State After K Multiplication Operations I
 */

// @lc code=start
class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    for (int op = 0; op < k; ++op) {
      int minIdx = 0;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[minIdx]) {
          minIdx = i;
        }
      }
      nums[minIdx] *= multiplier;
    }
    return nums;
  }
};
// @lc code=end
