/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
  int longestPalindrome(string s) {
    // INSERT_YOUR_CODE
    int count[128] = {0};
    for (char c : s) {
      count[c]++;
    }
    int res = 0;
    bool odd_found = false;
    for (int i = 0; i < 128; ++i) {
      res += (count[i] / 2) * 2;
      if (count[i] % 2 == 1)
        odd_found = true;
    }
    if (odd_found)
      res += 1;
    return res;
  }
};
// @lc code=end
