/*
 * @lc app=leetcode id=3280 lang=cpp
 *
 * [3280] Convert Date to Binary
 */

// @lc code=start
class Solution {
public:
  string convertDateToBinary(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    string year_bin = std::bitset<16>(year).to_string();
    year_bin = year_bin.substr(year_bin.find('1'));
    string month_bin = std::bitset<8>(month).to_string();
    month_bin = month_bin.substr(month_bin.find('1'));
    string day_bin = std::bitset<8>(day).to_string();
    day_bin = day_bin.substr(day_bin.find('1'));
    return year_bin + "-" + month_bin + "-" + day_bin;
  }
};
// @lc code=end
