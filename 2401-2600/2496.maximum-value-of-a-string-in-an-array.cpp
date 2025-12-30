/*
 * @lc app=leetcode id=2496 lang=cpp
 *
 * [2496] Maximum Value of a String in an Array
 */

// @lc code=start
class Solution {
public:
  int maximumValue(vector<string> &strs) {
    int maxVal = 0;
    for (const string &s : strs) {
      bool isDigit = true;
      for (char c : s) {
        if (!isdigit(c)) {
          isDigit = false;
          break;
        }
      }
      int val;
      if (isDigit) {
        val = stoi(s);
      } else {
        val = s.length();
      }
      if (val > maxVal)
        maxVal = val;
    }
    return maxVal;
  }
};
// @lc code=end
