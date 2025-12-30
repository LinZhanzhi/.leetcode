/*
 * @lc app=leetcode id=2409 lang=cpp
 *
 * [2409] Count Days Spent Together
 */

// @lc code=start
class Solution {
public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    auto dateToDayOfYear = [](const string &date) -> int {
      static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};
      int month = stoi(date.substr(0, 2));
      int day = stoi(date.substr(3, 2));
      int dayOfYear = day;
      for (int m = 0; m < month - 1; ++m) {
        dayOfYear += daysInMonth[m];
      }
      return dayOfYear;
    };

    int start = max(dateToDayOfYear(arriveAlice), dateToDayOfYear(arriveBob));
    int end = min(dateToDayOfYear(leaveAlice), dateToDayOfYear(leaveBob));
    return max(0, end - start + 1);
  }
};
// @lc code=end
