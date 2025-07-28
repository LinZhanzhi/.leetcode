/*
 * @lc app=leetcode id=2287 lang=cpp
 *
 * [2287] Rearrange Characters to Make Target String
 */

// @lc code=start
class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    vector<int> s_count(26, 0), t_count(26, 0);
    for (char c : s) {
      s_count[c - 'a']++;
    }
    for (char c : target) {
      t_count[c - 'a']++;
    }
    int res = INT_MAX;
    for (int i = 0; i < 26; ++i) {
      if (t_count[i] > 0) {
        res = min(res, s_count[i] / t_count[i]);
      }
    }
    return res;
  }
};
// @lc code=end
