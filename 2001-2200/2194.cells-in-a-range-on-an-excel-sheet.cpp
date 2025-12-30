/*
 * @lc app=leetcode id=2194 lang=cpp
 *
 * [2194] Cells in a Range on an Excel Sheet
 */

// @lc code=start
class Solution {
public:
  vector<string> cellsInRange(string s) {
    vector<string> res;
    char col1 = s[0], col2 = s[3];
    char row1 = s[1], row2 = s[4];
    for (char c = col1; c <= col2; ++c) {
      for (char r = row1; r <= row2; ++r) {
        string cell;
        cell += c;
        cell += r;
        res.push_back(cell);
      }
    }
    return res;
  }
};
// @lc code=end
