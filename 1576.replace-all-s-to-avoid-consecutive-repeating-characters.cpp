/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

// @lc code=start
class Solution {
public:
  string modifyString(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        for (char c = 'a'; c <= 'z'; ++c) {
          // Check previous and next character
          if ((i == 0 || s[i - 1] != c) &&
              (i == s.size() - 1 || s[i + 1] != c)) {
            s[i] = c;
            break;
          }
        }
      }
    }
    return s;
  }
};
// @lc code=end
