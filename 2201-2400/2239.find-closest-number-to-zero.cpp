/*
 * @lc app=leetcode id=2239 lang=cpp
 *
 * [2239] Find Closest Number to Zero
 */

// @lc code=start
class Solution {
public:
  int findClosestNumber(vector<int> &nums) {
    int closest = nums[0];
    for (int num : nums) {
      if (abs(num) < abs(closest) ||
          (abs(num) == abs(closest) && num > closest)) {
        closest = num;
      }
    }
    return closest;
  }
};
// @lc code=end
