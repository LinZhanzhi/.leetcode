/*
 * @lc app=leetcode id=3427 lang=cpp
 *
 * [3427] Sum of Variable Length Subarrays
 */

// @lc code=start
class Solution {
public:
  int subarraySum(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int start = max(0, i - nums[i]);
      total += prefix[i + 1] - prefix[start];
    }
    return total;
  }
};
// @lc code=end
