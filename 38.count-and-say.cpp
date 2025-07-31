/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1)
      return "1";
    string res = "1";
    for (int i = 2; i <= n; ++i) {
      string next = "";
      int len = res.size();
      for (int j = 0; j < len;) {
        char curr = res[j];
        int count = 0;
        while (j < len && res[j] == curr) {
          ++count;
          ++j;
        }
        next += to_string(count) + curr;
      }
      res = next;
    }
    return res;
  }
};
// @lc code=end
