/*
 * @lc app=leetcode id=2351 lang=cpp
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
class Solution {
public:
  char repeatedCharacter(string s) {
    vector<bool> seen(26, false);
    for (char c : s) {
      if (seen[c - 'a']) {
        return c;
      }
      seen[c - 'a'] = true;
    }
    return ' '; // This line will never be reached due to constraints
  }
};
// @lc code=end
