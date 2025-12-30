/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    // dp[i][j] = min distance to convert word1[0, i) to word2[0, j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // initialize dp[i][0] and dp[0][j]
    // dp[i][0] = i, because we need to delete i characters to convert word1[0,
    // i) to word2[0, 0)
    for (int i = 0; i <= m; ++i)
      dp[i][0] = i;
    // dp[0][j] = j, because we need to insert j characters to convert word1[0,
    // 0) to word2[0, j)
    for (int j = 0; j <= n; ++j)
      dp[0][j] = j;
    // calculate dp[i][j]
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min({
                             dp[i - 1][j],    // delete
                             dp[i][j - 1],    // insert
                             dp[i - 1][j - 1] // replace
                         });
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
