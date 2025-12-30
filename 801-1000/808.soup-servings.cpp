/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start

/*
Brief Digested Understanding:
----
This problem asks for the probability that soup A will be emptied before soup B
(or at the same time, with a half-probability payoff in that case), given two
soups A and B, each starting with n mL. Each turn, we randomly choose one of
four specific serving combinations that reduce A and B by prescribed amounts.
The process ends as soon as either A or B is depleted (i.e., becomes zero or
negative). We must account for all paths where A becomes empty first, or both
A and B become empty simultaneously.

High-Level Summary:
----
To efficiently compute the result, we use recursion with memoization (dynamic
programming), since the problem's overlapping subproblems fit this pattern.
We discretize n (dividing by 25 and rounding up), as each operation is a
multiple of 25, allowing for a finite state space. For large enough n,
the probability converges to 1. We'll cache intermediate results to
avoid recomputation. Each state is defined by the remaining units of (A, B),
and we recursively sum up the results of the four equally-likely next moves.
Time complexity is roughly O(n^2) for small n after discretization, but we
cap n at a reasonable upper bound (because for large n, the answer is
effectively 1). Space complexity is O(n^2) for the DP table.
*/

#include <vector>
using std::vector;

class Solution {
public:
  // The main function to return the probability answer
  double soupServings(int n) {
    // For large n, probability approaches 1.0 (problem constraint: within 1e-5)
    // Experimentally, for n >= 4800, the answer is already > 0.99999
    if (n >= 4800)
      return 1.0;

    // Discretize n: since every operation is a multiple of 25, use n =
    // ceil(n/25)
    int N = (n + 24) / 25;

    // Memoization table: dp[a][b] = probability with 'a' units of A and 'b'
    // units of B left
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1.0));
    return calcProb(N, N, dp);
  }

private:
  // Helper function to compute the probability recursively with memoization
  double calcProb(int a, int b, vector<vector<double>> &dp) {
    // Base case 1: Both A and B are empty at same time
    if (a <= 0 && b <= 0)
      return 0.5;
    // Base case 2: A is empty but B is not
    if (a <= 0 && b > 0)
      return 1.0;
    // Base case 3: B is empty but A is not
    if (a > 0 && b <= 0)
      return 0.0;

    // If already computed, return cached value
    if (dp[a][b] >= 0.0)
      return dp[a][b];

    // Four possible choices, each with probability 0.25:
    // Serve (100, 0), (75, 25), (50, 50), or (25, 75)
    // Work with the discretized units (each = 25 mL)
    double ans = 0.0;
    ans += 0.25 * calcProb(a - 4, b, dp);     // 100mL from A, 0mL from B
    ans += 0.25 * calcProb(a - 3, b - 1, dp); // 75mL from A, 25mL from B
    ans += 0.25 * calcProb(a - 2, b - 2, dp); // 50mL from A, 50mL from B
    ans += 0.25 * calcProb(a - 1, b - 3, dp); // 25mL from A, 75mL from B

    // Cache and return
    dp[a][b] = ans;
    return ans;
  }
};
// @lc code=end
