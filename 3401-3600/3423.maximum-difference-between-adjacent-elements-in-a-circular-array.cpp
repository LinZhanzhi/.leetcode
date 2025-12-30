/*
 * @lc app=leetcode id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
class Solution {
public:
  int maxAdjacentDistance(vector<int> &nums) {
    int n = nums.size();
    int maxDiff = 0;
    for (int i = 0; i < n; ++i) {
      int next = (i + 1) % n;
      int diff = abs(nums[i] - nums[next]);
      if (diff > maxDiff) {
        maxDiff = diff;
      }
    }
    return maxDiff;
  }
};
// @lc code=end
