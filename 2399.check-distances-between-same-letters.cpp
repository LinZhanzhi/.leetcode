/*
 * @lc app=leetcode id=2399 lang=cpp
 *
 * [2399] Check Distances Between Same Letters
 */

// @lc code=start
class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    vector<int> first(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      int idx = s[i] - 'a';
      if (first[idx] == -1) {
        first[idx] = i;
      } else {
        int dist = i - first[idx] - 1;
        if (dist != distance[idx])
          return false;
      }
    }
    return true;
  }
};
// @lc code=end
