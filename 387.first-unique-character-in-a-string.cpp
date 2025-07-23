/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> count(26, 0);
    for (char c : s) {
      count[c - 'a']++;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (count[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
