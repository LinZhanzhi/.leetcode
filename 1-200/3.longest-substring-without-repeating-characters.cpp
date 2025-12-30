/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLen = 0;
    int left = 0;
    vector<int> lastIndex(128, -1); // ASCII

    for (int right = 0; right < n; ++right) {
      char c = s[right];
      if (lastIndex[c] >= left) {
        left = lastIndex[c] + 1;
      }
      lastIndex[c] = right;
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};
// @lc code=end
