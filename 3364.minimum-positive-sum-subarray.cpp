/*
 * @lc app=leetcode id=3364 lang=cpp
 *
 * [3364] Minimum Positive Sum Subarray
 */

// @lc code=start
class Solution {
public:
  int minimumSumSubarray(vector<int> &nums, int l, int r) {
    int n = nums.size();
    int res = INT_MAX;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    for (int len = l; len <= r; ++len) {
      for (int i = 0; i + len <= n; ++i) {
        int sum = prefix[i + len] - prefix[i];
        if (sum > 0) {
          res = min(res, sum);
        }
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
// @lc code=end
