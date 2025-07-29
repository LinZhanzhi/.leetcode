/*
 * @lc app=leetcode id=2765 lang=cpp
 *
 * [2765] Longest Alternating Subarray
 */

// @lc code=start
class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int n = nums.size();
    int maxLen = -1;
    int start = -1;       // start index of current alternating subarray
    int expectedDiff = 1; // the difference we expect at each step (+1 or -1)
    for (int i = 1; i < n; ++i) {
      if (start == -1) {
        // Not in a subarray, look for start
        if (nums[i] - nums[i - 1] == 1) {
          start = i - 1;
          expectedDiff = -1;
        }
      } else {
        // In a subarray, check if alternation continues
        if (nums[i] - nums[i - 1] == expectedDiff) {
          expectedDiff *= -1;
        } else {
          // Alternation broken
          maxLen = std::max(maxLen, i - start);
          // Check if we can start a new subarray from previous element
          if (nums[i] - nums[i - 1] == 1) {
            start = i - 1;
            expectedDiff = -1;
          } else {
            start = -1;
          }
        }
      }
    }
    // Check for subarray ending at the last element
    if (start != -1) {
      maxLen = std::max(maxLen, n - start);
    }
    return maxLen;
  }
};
// @lc code=end