/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    int n = s.size();
    int start = 0;
    for (int end = 0; end <= n; ++end) {
      if (end == n || s[end] == ' ') {
        std::reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
      }
    }
    return s;
  }
};
// @lc code=end
