/*
 * @lc app=leetcode id=3019 lang=cpp
 *
 * [3019] Number of Changing Keys
 */

// @lc code=start
class Solution {
public:
  int countKeyChanges(string s) {
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (tolower(s[i]) != tolower(s[i - 1])) {
        ++cnt;
      }
    }
    return cnt;
  }
};
// @lc code=end
