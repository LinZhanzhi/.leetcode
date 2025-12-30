/*
 * @lc app=leetcode id=1736 lang=cpp
 *
 * [1736] Latest Time by Replacing Hidden Digits
 */

// @lc code=start
class Solution {
public:
  string maximumTime(string time) {
    // INSERT_YOUR_CODE
    // Fill hour
    if (time[0] == '?') {
      if (time[1] == '?' || time[1] <= '3') {
        time[0] = '2';
      } else {
        time[0] = '1';
      }
    }
    if (time[1] == '?') {
      if (time[0] == '2') {
        time[1] = '3';
      } else {
        time[1] = '9';
      }
    }
    // Fill minute
    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?') {
      time[4] = '9';
    }
    return time;
  }
};
// @lc code=end
