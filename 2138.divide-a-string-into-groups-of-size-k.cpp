/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> res;
    int n = s.size();
    for (int i = 0; i < n; i += k) {
      string group = s.substr(i, k);
      if (group.size() < k) {
        group += string(k - group.size(), fill);
      }
      res.push_back(group);
    }
    return res;
  }
};
// @lc code=end
