/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

// @lc code=start
class Solution {
public:
  string makeFancyString(string s) {
    string res;
    for (char c : s) {
      int n = res.size();
      if (n >= 2 && res[n - 1] == c && res[n - 2] == c) {
        continue;
      }
      res.push_back(c);
    }
    return res;
  }
};
// @lc code=end
