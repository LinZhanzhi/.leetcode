/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding the probability that, in a turn-based random
 * process resembling the card game "21", Alice ends up with a total score
 * between 0 and n (inclusive) after she stops drawing. Each turn, if her score
 * is less than k, she randomly adds a number from 1 to maxPts to her score.
 * She stops once her score reaches at least k. We need the probability that her
 * final score after stopping is at most n.
 */

/*
 * High-Level Summary:
 * ----
 * To solve this, we use dynamic programming. Let dp[x] represent the
 * probability that Alice ends up with at most n points if she currently has x
 * points. The base cases are that if x >= k, Alice stops and wins iff x <= n.
 * Otherwise, dp[x] is the average of dp[x+1], ..., dp[x+maxPts], reflecting
 * the possible next moves. We compute dp backwards from n down to 0 using a
 * sliding window sum for efficiency. The overall solution uses O(n) time and
 * space due to the DP array and a running sum for the window.
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
  // Main function to compute probability Alice gets n or fewer points.
  double new21Game(int n, int k, int maxPts) {
    // Edge case: If k == 0, Alice never draws, always has 0 points.
    // If n >= 0, probability is 1.
    if (k == 0 || n >= k + maxPts - 1)
      return 1.0;

    // dp[x]: Probability of getting no more than n points,
    // starting from x points.
    vector<double> dp(n + 1, 0.0);

    // For x in [k, n], Alice stops drawing, and she "wins"
    // (has <= n points). So, set dp[x] = 1.0.
    for (int x = k; x <= n; ++x) {
      dp[x] = 1.0;
    }

    // sumProb is the "window sum": sum of dp[x+1] to dp[x+maxPts].
    // Initialize with the sum for the last k...n entries (those are 1's)
    double sumProb =
        n - k + 1; // Number of 1's in dp[k] to dp[min(n, k+maxPts-1)]

    // Fill dp[x] from k-1 down to 0
    for (int x = k - 1; x >= 0; --x) {
      // The probability to win from x is the average of the next maxPts results
      dp[x] = sumProb / maxPts;

      // Update the sliding window:
      // Add dp[x] (just calculated), subtract dp[x + maxPts] (if in-bounds)
      if (x + maxPts <= n)
        sumProb += dp[x] - dp[x + maxPts];
      else
        sumProb += dp[x]; // No dp[x + maxPts] to subtract if out of bounds
    }

    // dp[0] stores the answer: probability of starting at 0 and ending <= n
    return dp[0];
  }
};
// @lc code=end
