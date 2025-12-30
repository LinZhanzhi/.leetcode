/*
 * @lc app=leetcode id=3438 lang=cpp
 *
 * [3438] Find Valid Pair of Adjacent Digits in String
 */

// @lc code=start
class Solution {
public:
  string findValidPair(string s) {
    vector<int> freq(10, 0);
    for (char c : s) {
      freq[c - '0']++;
    }
    for (int i = 0; i < (int)s.size() - 1; ++i) {
      char a = s[i], b = s[i + 1];
      if (a != b) {
        int va = a - '0', vb = b - '0';
        if (freq[va] == va && freq[vb] == vb) {
          return string() + a + b;
        }
      }
    }
    return "";
  }
};
// @lc code=end
