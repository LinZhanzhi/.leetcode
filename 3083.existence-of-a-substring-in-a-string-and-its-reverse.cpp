/*
 * @lc app=leetcode id=3083 lang=cpp
 *
 * [3083] Existence of a Substring in a String and Its Reverse
 */

// @lc code=start
class Solution {
public:
  bool isSubstringPresent(string s) {
    // INSERT_YOUR_CODE
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < n - 1; ++i) {
      string sub = s.substr(i, 2);
      if (rev.find(sub) != string::npos) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
