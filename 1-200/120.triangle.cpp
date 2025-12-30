/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    // We use a 1D dp array for space optimization
    vector<int> dp(triangle.back());
    // Start from the second last row and move upwards
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
      }
    }
    return dp[0];
  }
  //   int minimumTotal(vector<vector<int>> &triangle) {
  //     int n = triangle.size();
  //     vector<vector<int>> dp(n, vector<int>(n, 0));
  //     // dp[i][j] is the minimum path sum to the node at (i, j)
  //     // dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j])
  //     dp[0][0] = triangle[0][0];
  //     for (int i = 1; i < n; ++i) {
  //       for (int j = 0; j <= i; ++j) {
  //         if (j == 0) {
  //           dp[i][j] = dp[i - 1][j] + triangle[i][j];
  //         } else if (j == i) {
  //           dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
  //         } else {
  //           dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
  //         }
  //       }
  //     }
  //     int res = dp[n - 1][0];
  //     for (int j = 1; j < n; ++j) {
  //       res = min(res, dp[n - 1][j]);
  //     }
  //     return res;
  //   }
};
// @lc code=end
