/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
public:
  string removeOuterParentheses(string s) {
    string result;
    int depth = 0;
    for (char c : s) {
      if (c == '(') {
        if (depth > 0)
          result += c;
        depth++;
      } else {
        depth--;
        if (depth > 0)
          result += c;
      }
    }
    return result;
  }
};
// @lc code=end
