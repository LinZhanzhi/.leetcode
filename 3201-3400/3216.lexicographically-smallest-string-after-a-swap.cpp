/*
 * @lc app=leetcode id=3216 lang=cpp
 *
 * [3216] Lexicographically Smallest String After a Swap
 */

// @lc code=start
class Solution {
public:
  string getSmallestString(string s) {
    // INSERT_YOUR_CODE
    int n = s.size();
    string ans = s;
    for (int i = 0; i < n - 1; ++i) {
      // Check if adjacent digits have the same parity
      if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
        string t = s;
        swap(t[i], t[i + 1]);
        if (t < ans) {
          ans = t;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
