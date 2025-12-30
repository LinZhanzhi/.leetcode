/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

// @lc code=start
class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    static const vector<string> days = {"Sunday",    "Monday",   "Tuesday",
                                        "Wednesday", "Thursday", "Friday",
                                        "Saturday"};
    static const vector<int> month_days = {31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31};

    auto isLeap = [](int y) {
      return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    };

    // Count total days from 1971/1/1 to the given date
    int total_days = 0;
    // Add days for the years
    for (int y = 1971; y < year; ++y) {
      total_days += 365 + isLeap(y);
    }
    // Add days for the months in the current year
    for (int m = 1; m < month; ++m) {
      if (m == 2 && isLeap(year))
        total_days += 29;
      else
        total_days += month_days[m - 1];
    }
    // Add days in the current month
    total_days += day - 1;
    // 1971-01-01 is a Friday, which is index 5
    return days[(total_days + 5) % 7];
  }
};
// @lc code=end
