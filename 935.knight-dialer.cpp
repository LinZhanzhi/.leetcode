/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// Brief Digested Understanding:
// -----
// This problem asks: If we place a chess knight on a phone keypad and move it
// in the classic "L"-shaped steps, how many distinct digit sequences of length
// n can we form? Each move must be a valid knight jump to another numeric cell,
// and the knight may start on any digit. The knight can stand on digits 0-9
// (but not the '*' or '#' keys that do not exist in our problem). We return the
// count of such sequences modulo 1,000,000,007. Key constraints: n can be as
// large as 5000 (so brute-force is impossible); for n == 1, the answer is 10
// since you may start on any digit.

// High-Level Summary:
// -----
// We'll solve the problem using **dynamic programming**. At every step k (from
// 1 to n), for each digit d, we compute how many ways there are to reach digit
// d after k moves. The main idea is to iteratively update the number of ways to
// arrive at each digit, based on which digits can jump to it using knight's
// moves. We only need to keep track of two arrays for DP (previous and current
// step), keeping space usage low. We'll use a fixed adjacency list (mapping of
// knight moves on the keypad) to describe valid moves. This yields a time
// complexity of O(n*10) (for each step, compute for each digit), which is
// efficient for n ≤ 5000. Space complexity is O(10) due to rolling arrays for
// DP.

// @lc code=start
#include <vector>
using std::vector;

class Solution {
private:
  static const int MOD = 1000000007;

  // Helper function: Returns the neighbors for each digit that a knight can
  // reach.
  const vector<vector<int>> &knightNeighbors() {
    // Mapping from digit to all reachable digits with a knight's move
    // 0 goes to 4, 6
    // 1 goes to 6, 8
    // 2 goes to 7, 9
    // 3 goes to 4, 8
    // 4 goes to 0, 3, 9
    // 5 goes nowhere
    // 6 goes to 0, 1, 7
    // 7 goes to 2, 6
    // 8 goes to 1, 3
    // 9 goes to 2, 4
    static const vector<vector<int>> adj = {
        {4, 6},    // 0
        {6, 8},    // 1
        {7, 9},    // 2
        {4, 8},    // 3
        {0, 3, 9}, // 4
        {},        // 5 (no moves from 5)
        {0, 1, 7}, // 6
        {2, 6},    // 7
        {1, 3},    // 8
        {2, 4}     // 9
    };
    return adj;
  }

public:
  int knightDialer(int n) {
    // dp[d]: number of ways to build a sequence of length 'prev step'
    // ending at digit d
    vector<int> dp(10, 1); // At step 1, you can start at any digit: 1 way each

    // For each step beyond the first, update reachable and counts
    for (int step = 2; step <= n; ++step) {
      vector<int> next_dp(10, 0); // next set of counts to fill in for this step
      const auto &adj = knightNeighbors(); // digit move map

      for (int d = 0; d <= 9; ++d) {
        // For each digit, sum up the ways to reach it
        // from its possible neighbors in the previous step
        for (int from : adj[d]) {
          next_dp[d] = (next_dp[d] + dp[from]) % MOD;
        }
      }
      dp = std::move(next_dp); // Move for efficiency as we no longer need
                               // previous step values
    }

    // Sum all ways to end at any digit after n steps
    int total = 0;
    for (int count : dp) {
      total = (total + count) % MOD;
    }
    return total;
  }
};
// @lc code=end
