/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
  int maximum69Number(int num) {
    string s = to_string(num);
    for (char &c : s) {
      if (c == '6') {
        c = '9';
        break;
      }
    }
    return stoi(s);
  }
};
// @lc code=end
