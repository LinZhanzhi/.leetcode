/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem is about transforming a single 'A' on a notepad into exactly n
 * 'A's using only two operations: "Copy All" (copies the entire current
 * content) and "Paste" (pastes the last copied content). The goal is to find
 * the minimum number of operations needed to reach exactly n 'A's. The
 * challenge is to determine the optimal sequence of copy and paste operations
 * to minimize the total steps. The key insight is that the process is related
 * to breaking down n into its factors, as each "Copy All" followed by several
 * "Paste" operations can be seen as multiplying the count of 'A's.
 *
 * High-Level Summary:
 * ----
 * To solve this problem efficiently, we use dynamic programming (DP). We define
 * dp[i] as the minimum number of steps to get exactly i 'A's. For each i from 2
 * to n, we check all possible divisors j of i (where j < i and i % j == 0).
 * If j is a divisor, we can reach i by first reaching j 'A's, then copying all,
 * and pasting (i/j - 1) times. The total steps for this path are dp[j] + (i/j).
 * We take the minimum over all such divisors. The time complexity is
 * O(n*sqrt(n)) because for each i, we check up to sqrt(i) divisors. Space
 * complexity is O(n).
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
  // Main function to compute the minimum number of steps to get n 'A's
  int minSteps(int n) {
    // Edge case: If n is 1, we already have one 'A', so no steps needed
    if (n == 1)
      return 0;

    // dp[i] will store the minimum steps to get i 'A's
    std::vector<int> dp(n + 1, 0);

    // Base case: 0 steps to get 1 'A'
    dp[1] = 0;

    // Fill dp array for all values from 2 to n
    for (int i = 2; i <= n; ++i) {
      // Initialize with the worst case: all pastes (i steps)
      dp[i] = i;
      // Try all possible divisors j of i (j < i)
      for (int j = 1; j <= i / 2; ++j) {
        // If j is a divisor of i
        if (i % j == 0) {
          // To get i 'A's: get to j 'A's, then copy all, then paste (i/j - 1)
          // times Total steps: dp[j] + (i/j)
          dp[i] = std::min(dp[i], dp[j] + (i / j));
        }
      }
    }
    // The answer is the minimum steps to get n 'A's
    return dp[n];
  }
};
// @lc code=end
