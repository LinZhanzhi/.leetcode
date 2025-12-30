/*
 * @lc app=leetcode id=3379 lang=cpp
 *
 * [3379] Transformed Array
 */

// @lc code=start
class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        result[i] = nums[i];
      } else {
        int steps = nums[i];
        int idx;
        if (steps > 0) {
          idx = (i + steps) % n;
        } else {
          // For negative steps, move left
          idx = (i + (steps % n) + n) % n;
        }
        result[i] = nums[idx];
      }
    }
    return result;
  }
};
// @lc code=end
