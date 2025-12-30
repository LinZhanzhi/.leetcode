/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
  int countSegments(string s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
