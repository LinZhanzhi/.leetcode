/*
 * @lc app=leetcode id=3010 lang=cpp
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */

// @lc code=start
class Solution {
public:
  int minimumCost(vector<int> &nums) {
    int n = nums.size();
    int res = INT_MAX;
    // We need to split nums into 3 contiguous subarrays.
    // Let the first subarray be nums[0..i-1], second nums[i..j-1], third
    // nums[j..n-1] i in [1, n-1), j in [i+1, n)
    for (int i = 1; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int cost = nums[0] + nums[i] + nums[j];
        res = min(res, cost);
      }
    }
    return res;
  }
};
// @lc code=end
