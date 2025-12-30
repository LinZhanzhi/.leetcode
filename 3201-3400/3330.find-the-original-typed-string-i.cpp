/*
 * @lc app=leetcode id=3330 lang=cpp
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start
class Solution {
public:
  int possibleStringCount(string word) {
    int cnt = 0;
    for (int i = 1; i < word.size(); ++i) {
      if (word[i] == word[i - 1]) {
        cnt++;
      }
    }
    return cnt + 1;
  }
};
// @lc code=end
