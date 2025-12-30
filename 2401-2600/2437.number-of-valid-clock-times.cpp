/*
 * @lc app=leetcode id=2437 lang=cpp
 *
 * [2437] Number of Valid Clock Times
 */

// @lc code=start
class Solution {
public:
  int countTime(string time) {
    int hour_count = 0, min_count = 0;
    // Count valid hours
    for (int h = 0; h < 24; ++h) {
      int h1 = h / 10, h2 = h % 10;
      if ((time[0] == '?' || time[0] - '0' == h1) &&
          (time[1] == '?' || time[1] - '0' == h2)) {
        ++hour_count;
      }
    }
    // Count valid minutes
    for (int m = 0; m < 60; ++m) {
      int m1 = m / 10, m2 = m % 10;
      if ((time[3] == '?' || time[3] - '0' == m1) &&
          (time[4] == '?' || time[4] - '0' == m2)) {
        ++min_count;
      }
    }
    return hour_count * min_count;
  }
};
// @lc code=end
