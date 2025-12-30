/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
  bool validPalindrome(string s) {
    auto isPalindrome = [](const string &str, int l, int r) {
      while (l < r) {
        if (str[l] != str[r])
          return false;
        ++l;
        --r;
      }
      return true;
    };
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        // Try skipping either left or right character
        return isPalindrome(s, left + 1, right) ||
               isPalindrome(s, left, right - 1);
      }
      ++left;
      --right;
    }
    return true;
  }
};
// @lc code=end
