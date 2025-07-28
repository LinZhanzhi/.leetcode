/*
 * @lc app=leetcode id=2255 lang=cpp
 *
 * [2255] Count Prefixes of a Given String
 */

// @lc code=start
class Solution {
public:
  int countPrefixes(vector<string> &words, string s) {
    int count = 0;
    for (const string &word : words) {
      if (s.substr(0, word.size()) == word) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
