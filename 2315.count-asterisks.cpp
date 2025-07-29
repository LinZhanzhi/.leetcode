/*
 * @lc app=leetcode id=2315 lang=cpp
 *
 * [2315] Count Asterisks
 */

// @lc code=start
class Solution {
public:
  int countAsterisks(string s) {
    int count = 0;
    bool betweenBars = false;
    for (char c : s) {
      if (c == '|') {
        betweenBars = !betweenBars;
      } else if (c == '*' && !betweenBars) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
