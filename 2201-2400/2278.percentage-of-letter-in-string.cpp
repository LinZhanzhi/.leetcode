/*
 * @lc app=leetcode id=2278 lang=cpp
 *
 * [2278] Percentage of Letter in String
 */

// @lc code=start
class Solution {
public:
  int percentageLetter(string s, char letter) {
    int count = 0;
    for (char c : s) {
      if (c == letter)
        count++;
    }
    return (count * 100) / s.size();
  }
};
// @lc code=end
