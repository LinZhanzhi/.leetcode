/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
  string freqAlphabets(string s) {
    string res;
    int n = s.size();
    for (int i = 0; i < n;) {
      if (i + 2 < n && s[i + 2] == '#') {
        // It's a two-digit number followed by '#'
        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
        res += ('a' + num - 1);
        i += 3;
      } else {
        // It's a single digit
        int num = s[i] - '0';
        res += ('a' + num - 1);
        i += 1;
      }
    }
    return res;
  }
};
// @lc code=end
