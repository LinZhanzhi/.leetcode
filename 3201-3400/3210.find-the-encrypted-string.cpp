/*
 * @lc app=leetcode id=3210 lang=cpp
 *
 * [3210] Find the Encrypted String
 */

// @lc code=start
class Solution {
public:
  string getEncryptedString(string s, int k) {
    int n = s.size();
    string res(n, ' ');
    k = k % n;
    for (int i = 0; i < n; ++i) {
      res[i] = s[(i + k) % n];
    }
    return res;
  }
};
// @lc code=end
