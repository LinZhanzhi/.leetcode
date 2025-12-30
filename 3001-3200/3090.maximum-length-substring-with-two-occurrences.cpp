/*
 * @lc app=leetcode id=3090 lang=cpp
 *
 * [3090] Maximum Length Substring With Two Occurrences
 */

// @lc code=start
class Solution {
public:
  int maximumLengthSubstring(string s) {
    int n = s.size();
    int left = 0, right = 0;
    int freq[26] = {0};
    int maxLen = 0;
    while (right < n) {
      freq[s[right] - 'a']++;
      while (freq[s[right] - 'a'] > 2) {
        freq[s[left] - 'a']--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
    return maxLen;
  }
};
// @lc code=end
