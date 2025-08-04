/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    // Convert wordDict to a set for O(1) lookup
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();

    // dp[i] will be true if s[0:i) can be segmented into words from wordDict
    vector<bool> dp(n + 1, false);
    dp[0] = true; // s[0:0) is trivially true

    // Fill dp table
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        // If s[0:j) can be segmented and s[j:i) is in wordDict, then s[0:i) can
        // be segmented
        if (dp[j] && dict.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }

    // dp[n] will be true if s[0:n) can be segmented into words from wordDict
    return dp[n];
  }
};
// @lc code=end
