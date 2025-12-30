/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> res;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        if (words[j].find(words[i]) != string::npos) {
          res.push_back(words[i]);
          break;
        }
      }
    }
    return res;
  }
};
// @lc code=end
