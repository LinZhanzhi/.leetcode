/*
 * @lc app=leetcode id=2259 lang=cpp
 *
 * [2259] Remove Digit From Number to Maximize Result
 */

// @lc code=start
class Solution {
public:
  string removeDigit(string number, char digit) {
    string res = "";
    for (int i = 0; i < number.size(); ++i) {
      if (number[i] == digit) {
        string candidate = number.substr(0, i) + number.substr(i + 1);
        if (candidate > res) {
          res = candidate;
        }
      }
    }
    return res;
  }
};
// @lc code=end
