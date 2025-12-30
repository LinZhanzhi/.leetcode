/*
 * @lc app=leetcode id=2873 lang=cpp
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */

// @lc code=start
class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    if (n < 3)
      return 0;
    // Precompute left max for each position
    vector<int> left_max(n, 0);
    left_max[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      left_max[i] = max(left_max[i - 1], nums[i]);
    }
    // Precompute right max for each position
    vector<int> right_max(n, 0);
    right_max[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right_max[i] = max(right_max[i + 1], nums[i]);
    }
    long long res = 0;
    // For each j, compute (left_max[j-1] - nums[j]) * right_max[j+1]
    for (int j = 1; j < n - 1; ++j) {
      int left = left_max[j - 1];
      int right = right_max[j + 1];
      long long val = (long long)(left - nums[j]) * right;
      res = max(res, val);
    }
    return res;
  }
};
// @lc code=end
