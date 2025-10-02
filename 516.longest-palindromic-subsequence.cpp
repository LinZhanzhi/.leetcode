/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the length of the longest subsequence within a
 * given string that is also a palindrome. A subsequence is a sequence that can
 * be formed by deleting some (or no) characters from the string without
 * changing the order of the remaining characters. The goal is not to find the
 * substring (which requires consecutive characters), but any sequence of
 * characters that reads the same forwards and backwards.
 *
 * High-Level Summary:
 * ----
 * The standard approach to this problem is to use dynamic programming (DP).
 * We define a 2D DP table where dp[i][j] represents the length of the longest
 * palindromic subsequence in the substring s[i..j]. We fill this table by
 * considering all possible substrings, starting from the shortest and building
 * up to the full string. If the characters at the ends of the substring match,
 * we can include them and add 2 to the result for the inner substring.
 * Otherwise, we take the maximum result by either excluding the left or the
 * right character. The final answer is found at dp[0][n-1], where n is the
 * length of the string.
 *
 * Time Complexity: O(n^2), where n is the length of the string, since we fill
 * an n x n table. Space Complexity: O(n^2) for the DP table.
 */

#include <string>
#include <vector>
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the length of the longest palindromic subsequence
  int longestPalindromeSubseq(string s) {
    int n = s.size(); // Get the length of the input string

    // Edge case: if the string is empty or has only one character, return its
    // length
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    // Create a 2D DP table initialized to 0
    // dp[i][j] will store the length of the longest palindromic subsequence in
    // s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Helper function to initialize the DP table for substrings of length 1
    initializeSingleCharPalindromes(dp, n);

    // Fill the DP table for substrings of length 2 up to n
    fillDPTable(s, dp, n);

    // The answer is the length of the longest palindromic subsequence in the
    // whole string
    return dp[0][n - 1];
  }

private:
  // Helper function to initialize dp[i][i] = 1 for all i (single characters are
  // palindromes)
  void initializeSingleCharPalindromes(vector<vector<int>> &dp, int n) {
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1; // Every single character is a palindrome of length 1
    }
  }

  // Helper function to fill the DP table for all substring lengths > 1
  void fillDPTable(const string &s, vector<vector<int>> &dp, int n) {
    // Consider all substring lengths from 2 up to n
    for (int len = 2; len <= n; ++len) {
      // For each possible starting index of the substring
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1; // Ending index of the substring

        if (s[i] == s[j]) {
          // If the characters at both ends match, they can be part of the
          // palindrome Add 2 to the result for the inner substring (i+1, j-1)
          if (len == 2) {
            // Special case: two matching characters next to each other
            dp[i][j] = 2;
          } else {
            dp[i][j] = 2 + dp[i + 1][j - 1];
          }
        } else {
          // If the characters do not match, take the maximum by excluding
          // either end
          dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
  }
};
// @lc code=end
