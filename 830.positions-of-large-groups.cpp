/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> res;
    int n = s.size();
    int i = 0;
    while (i < n) {
      int j = i;
      while (j < n && s[j] == s[i]) {
        ++j;
      }
      if (j - i >= 3) {
        res.push_back({i, j - 1});
      }
      i = j;
    }
    return res;
  }
};
// @lc code=end
