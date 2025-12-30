/*
 * @lc app=leetcode id=3114 lang=cpp
 *
 * [3114] Latest Time You Can Obtain After Replacing Characters
 */

// @lc code=start
class Solution {
public:
  string findLatestTime(string s) {
    // Try to maximize each digit, respecting 12-hour format constraints
    string res = s;

    // Handle hours
    if (res[0] == '?' && res[1] == '?') {
      // "11" is the latest valid hour
      res[0] = '1';
      res[1] = '1';
    } else if (res[0] == '?') {
      // res[1] is known
      if (res[1] >= '0' && res[1] <= '1') {
        // "10" or "11" is possible
        res[0] = '1';
      } else {
        // "00" to "09"
        res[0] = '0';
      }
    } else if (res[1] == '?') {
      // res[0] is known
      if (res[0] == '1') {
        // "10" or "11"
        res[1] = '1';
      } else {
        // "00" to "09"
        res[1] = '9';
      }
    }

    // Handle minutes
    if (res[3] == '?') {
      res[3] = '5';
    }
    if (res[4] == '?') {
      res[4] = '9';
    }

    return res;
  }
};
// @lc code=end
