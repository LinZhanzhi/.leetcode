/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
class Solution {
public:
  int secondHighest(string s) {
    vector<bool> seen(10, false);
    for (char c : s) {
      if (isdigit(c)) {
        seen[c - '0'] = true;
      }
    }
    int count = 0;
    for (int i = 9; i >= 0; --i) {
      if (seen[i]) {
        ++count;
        if (count == 2)
          return i;
      }
    }
    return -1;
  }
};
// @lc code=end
