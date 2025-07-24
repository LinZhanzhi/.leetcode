/*
 * @lc app=leetcode id=1360 lang=cpp
 *
 * [1360] Number of Days Between Two Dates
 */

// @lc code=start
class Solution {
public:
  int daysBetweenDates(string date1, string date2) {
    auto isLeap = [](int year) {
      return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    };
    auto daysFromEpoch = [&](const string &date) {
      int y = stoi(date.substr(0, 4));
      int m = stoi(date.substr(5, 2));
      int d = stoi(date.substr(8, 2));
      static int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};
      int days = 0;
      // Add days for full years
      for (int year = 1971; year < y; ++year) {
        days += isLeap(year) ? 366 : 365;
      }
      // Add days for full months in current year
      for (int month = 1; month < m; ++month) {
        if (month == 2 && isLeap(y)) {
          days += 29;
        } else {
          days += daysInMonth[month - 1];
        }
      }
      // Add days in current month
      days += d;
      return days;
    };
    return abs(daysFromEpoch(date1) - daysFromEpoch(date2));
  }
};
// @lc code=end
