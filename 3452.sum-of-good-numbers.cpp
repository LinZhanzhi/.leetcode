/*
 * @lc app=leetcode id=3452 lang=cpp
 *
 * [3452] Sum of Good Numbers
 */

// @lc code=start
class Solution {
public:
  int sumOfGoodNumbers(vector<int> &nums, int k) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      bool good = true;
      if (i - k >= 0 && nums[i] <= nums[i - k])
        good = false;
      if (i + k < n && nums[i] <= nums[i + k])
        good = false;
      if (good)
        sum += nums[i];
    }
    return sum;
  }
};
// @lc code=end
