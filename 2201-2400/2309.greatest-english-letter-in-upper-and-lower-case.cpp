/*
 * @lc app=leetcode id=2309 lang=cpp
 *
 * [2309] Greatest English Letter in Upper and Lower Case
 */

// @lc code=start
class Solution {
public:
  string greatestLetter(string s) {
    vector<bool> upper(26, false), lower(26, false);
    for (char c : s) {
      if (isupper(c))
        upper[c - 'A'] = true;
      if (islower(c))
        lower[c - 'a'] = true;
    }
    for (int i = 25; i >= 0; --i) {
      if (upper[i] && lower[i]) {
        string res(1, 'A' + i);
        return res;
      }
    }
    return "";
  }
};
// @lc code=end
