/*
 * @lc app=leetcode id=3392 lang=cpp
 *
 * [3392] Count Subarrays of Length Three With a Condition
 */

// @lc code=start
class Solution {
public:
  int countSubarrays(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i + 2 < nums.size(); ++i) {
      // Check if sum of first and third equals half of the second
      if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
