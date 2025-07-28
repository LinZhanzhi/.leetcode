/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int count = 0;
    for (const string &word : words) {
      if (word.substr(0, pref.size()) == pref) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
