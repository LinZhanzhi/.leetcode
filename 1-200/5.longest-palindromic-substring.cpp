/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0)
      return "";

    int start = 0, maxLen = 1;

    auto expandAroundCenter = [&](int left, int right) {
      while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
      }
      // After the loop, s[left+1..right-1] is palindrome
      int len = right - left - 1;
      if (len > maxLen) {
        maxLen = len;
        start = left + 1;
      }
    };

    for (int i = 0; i < n; ++i) {
      expandAroundCenter(i, i);     // Odd length palindrome
      expandAroundCenter(i, i + 1); // Even length palindrome
    }

    return s.substr(start, maxLen);
  }
};
// @lc code=end
