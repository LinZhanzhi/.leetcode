/*
 * @lc app=leetcode id=3120 lang=cpp
 *
 * [3120] Count the Number of Special Characters I
 */

// @lc code=start
class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<bool> lower(26, false), upper(26, false);
    for (char c : word) {
      if (islower(c))
        lower[c - 'a'] = true;
      else if (isupper(c))
        upper[c - 'A'] = true;
    }
    int count = 0;
    for (int i = 0; i < 26; ++i) {
      if (lower[i] && upper[i])
        ++count;
    }
    return count;
  }
};
// @lc code=end
