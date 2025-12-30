/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
#include <algorithm> // To use the std::min function
#include <string>    // To use the std::string class
#include <vector>    // To use the std::vector class

using std::min;
using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * The goal is to find the minimum total ASCII value of characters to delete
 * from two given strings so that the resulting strings are exactly the same. At
 * each position, you may choose to delete a character from either string or
 * keep matching ones, and the cost of deletion is the ASCII value of the
 * deleted character. This is essentially a variant of the string edit-distance
 * problem where only deletion is allowed and cost is based on the ASCII value
 * of the deleted characters.
 *
 * High-Level Summary:
 * ----
 * The solution uses dynamic programming (DP) to minimize the ASCII sum of
 * deleted characters to make the two strings equal. We build a DP table where
 * dp[i][j] represents the minimum delete sum for substrings s1[i:] and s2[j:].
 * The recursion is as follows: if s1[i] == s2[j], move forward with no cost;
 * otherwise, consider deleting s1[i] or s2[j] and take the option with minimal
 * cost. Edge cases where one string is empty are handled by summing the ASCII
 * codes of the leftover characters. The algorithm uses O(M*N) time and space,
 * where M and N are lengths of the two strings, which is efficient enough given
 * the constraints (<= 1000 each).
 */

// Helper function to compute the sum of ASCII values of all characters in a
// string
int asciiSum(const string &str, int startIdx) {
  // This function is useful for computing the cost to delete an entire
  // substring
  int sum = 0;
  for (int i = startIdx; i < str.size(); ++i) {
    sum += static_cast<int>(str[i]); // Cast character to ASCII integer value
  }
  return sum;
}

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // dp[i][j] represents the minimum delete sum for s1[i:] and s2[j:]
    // We use m+1 and n+1 because we might look at substrings beyond the last
    // character
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill out base cases:
    // If s1 is empty, delete all remaining characters in s2
    for (int j = n - 1; j >= 0; --j) {
      dp[m][j] = dp[m][j + 1] + static_cast<int>(s2[j]);
      // dp[m][j] is sum of ASCII values of s2[j:] to delete them all
    }
    // If s2 is empty, delete all remaining characters in s1
    for (int i = m - 1; i >= 0; --i) {
      dp[i][n] = dp[i + 1][n] + static_cast<int>(s1[i]);
      // dp[i][n] is sum of ASCII values of s1[i:] to delete them all
    }

    // Fill the DP table from bottom-right to top-left
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (s1[i] == s2[j]) {
          // If characters match, no deletion needed here, move to next chars
          dp[i][j] = dp[i + 1][j + 1];
        } else {
          // Else, try deleting either s1[i] or s2[j], and take the cheaper
          // option
          int deleteS1 = static_cast<int>(s1[i]) + dp[i + 1][j];
          int deleteS2 = static_cast<int>(s2[j]) + dp[i][j + 1];
          dp[i][j] = min(deleteS1, deleteS2);
        }
      }
    }
    // The answer for the entire strings is located at dp[0][0]
    return dp[0][0];
  }
};
// @lc code=end
