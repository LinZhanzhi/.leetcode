/*
 * @lc app=leetcode id=3456 lang=cpp
 *
 * [3456] Find Special Substring of Length K
 */

// @lc code=start
class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    int n = s.size();
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1]) {
        ++cnt;
      } else {
        if (cnt == k)
          return true;
        cnt = 1;
      }
    }
    return cnt == k;
  }
};
// @lc code=end
