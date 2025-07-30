/*
 * @lc app=leetcode id=3110 lang=cpp
 *
 * [3110] Score of a String
 */

// @lc code=start
class Solution {
public:
  int scoreOfString(string s) {
    int score = 0;
    for (int i = 1; i < s.size(); ++i) {
      score += abs(s[i] - s[i - 1]);
    }
    return score;
  }
};
// @lc code=end
