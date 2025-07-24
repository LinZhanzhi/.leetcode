/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
class Solution {
public:
  int dayOfYear(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Check for leap year
    bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (is_leap)
      days_in_month[1] = 29;
    int res = 0;
    for (int i = 0; i < month - 1; ++i) {
      res += days_in_month[i];
    }
    res += day;
    return res;
  }
};
// @lc code=end
