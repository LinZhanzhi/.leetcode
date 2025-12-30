/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks: Given two strings, what is the minimum number of
 * single-character deletions (from either string) needed to make the two
 * strings identical? The only allowed operation is deleting a character from
 * either string, and the goal is to make both strings exactly the same. The
 * core idea is to find the largest common part (subsequence) that both strings
 * can share, and then delete everything else.
 *
 * High-Level Summary:
 * ----
 * The optimal solution is based on finding the Longest Common Subsequence (LCS)
 * between the two strings. The LCS is the longest sequence of characters that
 * appears in both strings in the same order (not necessarily contiguous). To
 * make both strings equal, we need to delete all characters that are not part
 * of the LCS from both strings. Thus, the minimum number of deletions is:
 * (length of word1 - LCS) + (length of word2 - LCS). We use dynamic programming
 * to compute the LCS efficiently in O(m*n) time and space, where m and n are
 * the lengths of the two strings.
 */

#include <algorithm> // For std::max
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::max;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the minimum number of deletions
  int minDistance(string word1, string word2) {
    // Compute the length of the Longest Common Subsequence (LCS)
    int lcsLen = longestCommonSubsequence(word1, word2);
    // The minimum deletions needed is the sum of characters not in the LCS from
    // both strings
    return (word1.size() - lcsLen) + (word2.size() - lcsLen);
  }

private:
  // Helper function to compute the length of the Longest Common Subsequence
  // (LCS)
  int longestCommonSubsequence(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    // Create a 2D DP table where dp[i][j] represents the LCS length of
    // s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          // If characters match, extend the LCS by 1
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          // Otherwise, take the maximum LCS by skipping a character from either
          // string
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    // The bottom-right cell contains the length of the LCS for the entire
    // strings
    return dp[m][n];
  }
};
// @lc code=end
