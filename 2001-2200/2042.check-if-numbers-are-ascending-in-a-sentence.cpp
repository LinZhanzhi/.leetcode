/*
 * @lc app=leetcode id=2042 lang=cpp
 *
 * [2042] Check if Numbers Are Ascending in a Sentence
 */

// @lc code=start
class Solution {
public:
  bool areNumbersAscending(string s) {
    int prev = 0;
    int n = s.size();
    int i = 0;
    while (i < n) {
      // Skip spaces
      while (i < n && s[i] == ' ')
        ++i;
      if (i >= n)
        break;
      // Check if current token is a number
      if (isdigit(s[i])) {
        int num = 0;
        while (i < n && isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          ++i;
        }
        if (num <= prev)
          return false;
        prev = num;
      } else {
        // Skip word token
        while (i < n && s[i] != ' ')
          ++i;
      }
    }
    return true;
  }
};
// @lc code=end
