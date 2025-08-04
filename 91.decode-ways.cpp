/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    // If the string is empty or starts with '0', it cannot be decoded.
    if (n == 0 || s[0] == '0')
      return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty string
    dp[1] = 1; // first char s[0] is not '0' (checked above)
    // dp[i] = dp[i-1] + dp[i-2]
    // dp[i-1] is the number of ways to decode the string up to the (i-1)th
    // character.
    // dp[i-2] is the number of ways to decode the string up to the (i-2)th
    // character.
    for (int i = 2; i <= n; ++i) {
      // Single digit decode (s[i-1])
      if (s[i - 1] != '0') {
        dp[i] += dp[i - 1];
      }
      // Two digit decode (s[i-2]s[i-1])
      int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      if (two >= 10 && two <= 26) {
        dp[i] += dp[i - 2];
      }
    }
    return dp[n];
  }
};
// @lc code=end
