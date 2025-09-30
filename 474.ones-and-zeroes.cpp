/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of binary strings and two numbers, m and n. Our goal is
 * to select the largest possible subset of these strings such that the total
 * number of '0's in the subset is at most m, and the total number of '1's is at
 * most n. Each string can be used at most once, and we want to maximize the
 * number of strings in our chosen subset without exceeding the given limits for
 * '0's and '1's.
 *
 * High-Level Summary:
 * ----
 * This problem is a variation of the classic 0/1 Knapsack problem, but with two
 * constraints (the number of '0's and the number of '1's) instead of one. We
 * use dynamic programming (DP) to solve it efficiently. The DP table dp[i][j]
 * represents the maximum number of strings that can be chosen with at most i
 * '0's and j '1's. For each string, we count its '0's and '1's, and update the
 * DP table in reverse to avoid overcounting. The final answer is found in
 * dp[m][n]. The time complexity is O(L * m * n), where L is the number of
 * strings, and the space complexity is O(m * n).
 */

// Include necessary headers for vector and string usage.
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the largest subset of strs with at most m '0's and n
  // '1's.
  int findMaxForm(vector<string> &strs, int m, int n) {
    // Initialize a 2D DP table where dp[i][j] is the max number of strings
    // that can be formed with at most i '0's and j '1's.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Process each string in the input list.
    for (const string &s : strs) {
      // Count the number of '0's and '1's in the current string.
      int zeros = countChar(s, '0');
      int ones = countChar(s, '1');

      // Update the DP table in reverse order to avoid using the same string
      // multiple times. We iterate from m down to zeros and n down to ones.
      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          // For each cell, decide whether to include the current string or not.
          // If included, increment the count by 1 and subtract the string's
          // zeros and ones.
          dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }

    // The answer is the maximum number of strings that can be formed with at
    // most m '0's and n '1's.
    return dp[m][n];
  }

private:
  // Helper function to count the occurrences of a specific character in a
  // string.
  int countChar(const string &s, char ch) {
    int count = 0;
    for (char c : s) {
      if (c == ch)
        ++count;
    }
    return count;
  }
};
// @lc code=end
