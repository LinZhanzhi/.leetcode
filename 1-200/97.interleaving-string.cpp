/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size(), l = s3.size();
    if (n + m != l)
      return false; // s3's length must be equal to the sum of s1's
                    // and s2's length.
    vector<bool> dp(m + 1, false);
    // calculating row 0 of dp table, where s1 is not used. this is actually
    // dp[0][j] dp[0][0] is true because s1[0:0) and s2[0:0) are subsequences of
    // s3[0:0).
    dp[0] = true;
    for (int j = 1; j <= m; ++j) {
      dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    // calculating row 1 to row n of dp table, where s1 is used. so dp[j] is
    // actually dp[i][j]
    for (int i = 1; i <= n; ++i) {
      // first column of dp table, where s2 is not used. this is actually
      // dp[i][0] dp[0] is true if s1[0:i) is a subsequence of s3[0:i).
      dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
      // calculating other cells of dp table, where s1 and s2 are used.
      for (int j = 1; j <= m; ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] &&
                 s2[j - 1] ==
                     s3[i + j - 1]); // dp[j] is true if s1[0:i) and s2[0:j) are
                                     // subsequences of s3[0:i+j).
      }
    }
    return dp[m];
  }
  //   bool isInterleave(string s1, string s2, string s3) {
  //     int n = s1.size(), m = s2.size(), l = s3.size();
  //     if (n + m != l)
  //       return false;
  //     // dp[i][j] is true if s1[0:i) and s2[0:j) are subsequences of
  //     s3[0:i+j). vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  //     // dp[0][0] is true if s1[0:0) and s2[0:0) are subsequences of s3[0:0).
  //     dp[0][0] = true;
  //     // dp[i][j] is true if s1[0:i) and s2[0:j) are subsequences of
  //     s3[0:i+j).
  //     // calculate first row
  //     for (int j = 1; j <= m; ++j) {
  //       dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
  //     }
  //     // calculate first column
  //     for (int i = 1; i <= n; ++i) {
  //       dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
  //     }
  //     // calculate other cells
  //     for (int i = 1; i <= n; ++i) {
  //       for (int j = 1; j <= m; ++j) {
  //         // dp[i][j] is true if s1[0:i) and s2[0:j) are subsequences of
  //         // s3[0:i+j).
  //         dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
  //                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
  //       }
  //     }
  //     return dp[n][m];
  //   }
};
// @lc code=end
