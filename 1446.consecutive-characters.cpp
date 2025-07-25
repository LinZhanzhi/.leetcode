/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
public:
  int maxPower(string s) {
    int max_power = 1, curr_power = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++curr_power;
      } else {
        curr_power = 1;
      }
      if (curr_power > max_power) {
        max_power = curr_power;
      }
    }
    return max_power;
  }
};
// @lc code=end
