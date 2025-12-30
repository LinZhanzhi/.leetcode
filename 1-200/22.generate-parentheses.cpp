/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    function<void(string, int, int)> backtrack = [&](string curr, int open,
                                                     int close) {
      if (curr.size() == 2 * n) {
        result.push_back(curr);
        return;
      }
      if (open < n) {
        backtrack(curr + '(', open + 1, close);
      }
      if (close < open) {
        backtrack(curr + ')', open, close + 1);
      }
    };
    backtrack("", 0, 0);
    return result;
  }
};
// @lc code=end
