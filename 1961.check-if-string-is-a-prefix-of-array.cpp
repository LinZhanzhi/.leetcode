/*
 * @lc app=leetcode id=1961 lang=cpp
 *
 * [1961] Check If String Is a Prefix of Array
 */

// @lc code=start
class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    string concat;
    for (const string &word : words) {
      concat += word;
      if (concat.length() >= s.length()) {
        break;
      }
    }
    return concat == s;
  }
};
// @lc code=end
