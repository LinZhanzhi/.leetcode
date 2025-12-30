/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
  int balancedStringSplit(string s) {
    int count = 0, balance = 0;
    for (char c : s) {
      if (c == 'L')
        balance++;
      else
        balance--;
      if (balance == 0)
        count++;
    }
    return count;
  }
};
// @lc code=end
