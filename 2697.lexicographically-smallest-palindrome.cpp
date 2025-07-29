/*
 * @lc app=leetcode id=2697 lang=cpp
 *
 * [2697] Lexicographically Smallest Palindrome
 */

// @lc code=start
class Solution {
public:
  string makeSmallestPalindrome(string s) {
    // INSERT_YOUR_CODE
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - 1 - i]) {
        char smaller = min(s[i], s[n - 1 - i]);
        s[i] = s[n - 1 - i] = smaller;
      }
    }
    return s;
  }
};
// @lc code=end
