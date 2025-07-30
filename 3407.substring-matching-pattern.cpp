/*
 * @lc app=leetcode id=3407 lang=cpp
 *
 * [3407] Substring Matching Pattern
 */

// @lc code=start
class Solution {
public:
  bool hasMatch(string s, string p) {
    // INSERT_YOUR_CODE
    int star = p.find('*');
    string pre = p.substr(0, star);
    string suf = p.substr(star + 1);

    int minLen = pre.size() + suf.size();
    int n = s.size();
    for (int i = 0; i <= n - minLen; ++i) {
      // Check if s.substr(i, pre.size()) == pre
      if (pre.size() && s.substr(i, pre.size()) != pre)
        continue;
      // Check if we can find suf in s[i + pre.size() + 1, n]
      if (s.find(suf, i + pre.size()) != string::npos)
        return true;
    }
    return false;
  }
};
// @lc code=end
