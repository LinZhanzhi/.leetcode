/*
 * @lc app=leetcode id=3461 lang=cpp
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
class Solution {
public:
  bool hasSameDigits(string s) {
    while (s.length() > 2) {
      string next;
      for (int i = 0; i + 1 < s.length(); ++i) {
        int d1 = s[i] - '0';
        int d2 = s[i + 1] - '0';
        next += ((d1 + d2) % 10) + '0';
      }
      s = next;
    }
    return s[0] == s[1];
  }
};
// @lc code=end
