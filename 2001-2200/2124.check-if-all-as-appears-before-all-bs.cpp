/*
 * @lc app=leetcode id=2124 lang=cpp
 *
 * [2124] Check if All A's Appears Before All B's
 */

// @lc code=start
class Solution {
public:
  bool checkString(string s) {
    bool seen_b = false;
    for (char c : s) {
      if (c == 'b') {
        seen_b = true;
      } else if (c == 'a' && seen_b) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
