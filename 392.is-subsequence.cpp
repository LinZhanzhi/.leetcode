/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == m;
  }
};
// @lc code=end
