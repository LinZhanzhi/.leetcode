/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
public:
  bool checkRecord(string s) {
    int absents = 0;
    int lateStreak = 0;
    for (char c : s) {
      if (c == 'A') {
        absents++;
        if (absents >= 2)
          return false;
        lateStreak = 0;
      } else if (c == 'L') {
        lateStreak++;
        if (lateStreak >= 3)
          return false;
      } else {
        lateStreak = 0;
      }
    }
    return true;
  }
};
// @lc code=end
