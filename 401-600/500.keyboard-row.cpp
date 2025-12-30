/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    vector<string> res;
    // Map each letter to its row: 1, 2, or 3
    vector<int> row(26, 0);
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl";
    string row3 = "zxcvbnm";
    for (char c : row1)
      row[c - 'a'] = 1;
    for (char c : row2)
      row[c - 'a'] = 2;
    for (char c : row3)
      row[c - 'a'] = 3;
    for (const string &word : words) {
      int r = row[tolower(word[0]) - 'a'];
      bool valid = true;
      for (char c : word) {
        if (row[tolower(c) - 'a'] != r) {
          valid = false;
          break;
        }
      }
      if (valid)
        res.push_back(word);
    }
    return res;
  }
};
// @lc code=end
