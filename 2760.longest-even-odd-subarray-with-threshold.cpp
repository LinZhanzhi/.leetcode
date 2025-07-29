/*
 * @lc app=leetcode id=2760 lang=cpp
 *
 * [2760] Longest Even Odd Subarray With Threshold
 */

// @lc code=start
class Solution {
public:
  int longestAlternatingSubarray(vector<int> &nums, int threshold) {
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 != 0 || nums[i] > threshold)
        continue;
      int len = 1;
      int prev = nums[i];
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] > threshold)
          break;
        if ((nums[j] % 2) == (prev % 2))
          break;
        ++len;
        prev = nums[j];
      }
      maxLen = std::max(maxLen, len);
    }
    return maxLen;
  }
};
// @lc code=end
