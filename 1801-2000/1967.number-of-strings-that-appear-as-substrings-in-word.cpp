/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

// @lc code=start
class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int count = 0;
    for (const string &pattern : patterns) {
      if (word.find(pattern) != string::npos) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
