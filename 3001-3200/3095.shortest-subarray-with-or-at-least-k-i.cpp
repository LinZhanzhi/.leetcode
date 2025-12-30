/*
 * @lc app=leetcode id=3095 lang=cpp
 *
 * [3095] Shortest Subarray With OR at Least K I
 */

// @lc code=start
class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int minLen = n + 1;
    for (int i = 0; i < n; ++i) {
      int curr_or = 0;
      for (int j = i; j < n; ++j) {
        curr_or |= nums[j];
        if (curr_or >= k) {
          minLen = std::min(minLen, j - i + 1);
          break; // No need to check longer subarrays starting at i
        }
      }
    }
    return (minLen == n + 1) ? -1 : minLen;
  }
};
// @lc code=end
