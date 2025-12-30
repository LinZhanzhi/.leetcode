/*
 * @lc app=leetcode id=2843 lang=cpp
 *
 * [2843]   Count Symmetric Integers
 */

// @lc code=start
class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int res = 0;
    for (int x = low; x <= high; ++x) {
      string s = to_string(x);
      int len = s.size();
      if (len % 2 != 0)
        continue;
      int n = len / 2;
      int sum1 = 0, sum2 = 0;
      for (int i = 0; i < n; ++i)
        sum1 += s[i] - '0';
      for (int i = n; i < len; ++i)
        sum2 += s[i] - '0';
      if (sum1 == sum2)
        ++res;
    }
    return res;
  }
};
// @lc code=end
