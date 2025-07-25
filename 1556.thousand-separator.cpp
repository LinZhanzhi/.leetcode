/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

// @lc code=start
class Solution {
public:
  string thousandSeparator(int n) {
    string s = to_string(n);
    int len = s.length();
    string res;
    int count = 0;
    for (int i = len - 1; i >= 0; --i) {
      res.push_back(s[i]);
      count++;
      if (count % 3 == 0 && i != 0) {
        res.push_back('.');
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
