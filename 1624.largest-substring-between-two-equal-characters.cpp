/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    // INSERT_YOUR_CODE
    vector<int> first(26, -1);
    int res = -1;
    for (int i = 0; i < s.size(); ++i) {
      int idx = s[i] - 'a';
      if (first[idx] == -1) {
        first[idx] = i;
      } else {
        res = max(res, i - first[idx] - 1);
      }
    }
    return res;
  }
};
// @lc code=end
