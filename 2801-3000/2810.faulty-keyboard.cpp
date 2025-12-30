/*
 * @lc app=leetcode id=2810 lang=cpp
 *
 * [2810] Faulty Keyboard
 */

// @lc code=start
class Solution {
public:
  string finalString(string s) {
    string res;
    for (char c : s) {
      if (c == 'i') {
        reverse(res.begin(), res.end());
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
};
// @lc code=end
