/*
 * @lc app=leetcode id=3467 lang=cpp
 *
 * [3467] Transform Array by Parity
 */

// @lc code=start
class Solution {
public:
  vector<int> transformArray(vector<int> &nums) {
    for (int &num : nums) {
      if (num % 2 == 0) {
        num = 0;
      } else {
        num = 1;
      }
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};
// @lc code=end
