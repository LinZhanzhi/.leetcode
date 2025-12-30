/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */

// @lc code=start
class Solution {
public:
  string reformatDate(string date) {
    static const unordered_map<string, string> month_map = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    istringstream iss(date);
    string day, month, year;
    iss >> day >> month >> year;
    // Remove suffix from day
    day = day.substr(0, day.size() - 2);
    if (day.size() == 1)
      day = "0" + day;
    return year + "-" + month_map.at(month) + "-" + day;
  }
};
// @lc code=end
