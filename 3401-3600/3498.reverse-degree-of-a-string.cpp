/*
 * @lc app=leetcode id=3498 lang=cpp
 *
 * [3498] Reverse Degree of a String
 */

// @lc code=start
class Solution {
public:
  int reverseDegree(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      int rev_alpha_idx = 'z' - s[i] + 1;
      res += rev_alpha_idx * (i + 1);
    }
    return res;
  }
};
// @lc code=end
