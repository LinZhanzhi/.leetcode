/*
 * @lc app=leetcode id=2788 lang=cpp
 *
 * [2788] Split Strings by Separator
 */

// @lc code=start
class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
    vector<string> result;
    for (const string &word : words) {
      string curr;
      for (char c : word) {
        if (c == separator) {
          if (!curr.empty()) {
            result.push_back(curr);
            curr.clear();
          }
        } else {
          curr += c;
        }
      }
      if (!curr.empty()) {
        result.push_back(curr);
      }
    }
    return result;
  }
};
// @lc code=end
