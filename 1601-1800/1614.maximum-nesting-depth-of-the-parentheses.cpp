/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
  int maxDepth(string s) {
    int max_depth = 0;
    int current_depth = 0;
    for (char c : s) {
      if (c == '(') {
        current_depth++;
        if (current_depth > max_depth) {
          max_depth = current_depth;
        }
      } else if (c == ')') {
        current_depth--;
      }
    }
    return max_depth;
  }
};
// @lc code=end
