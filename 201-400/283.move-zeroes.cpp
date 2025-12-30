/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int nonZeroIndex = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[nonZeroIndex] = nums[i];
        nonZeroIndex++;
      }
    }

    // Fill the remaining positions with zeros
    for (int i = nonZeroIndex; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};
// @lc code=end
