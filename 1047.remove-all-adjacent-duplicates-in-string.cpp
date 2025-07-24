/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    // INSERT_YOUR_CODE
    string res;
    for (char c : s) {
      if (!res.empty() && res.back() == c) {
        res.pop_back();
      } else {
        res.push_back(c);
      }
    }
    return res;
  }
};
// @lc code=end
