/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

/*
 * Brief, Digested Understanding:
 * ----
 * In this problem, two players take turns picking numbers from either end of an
 * array, each trying to maximize their own total score. Both play optimally. We
 * need to determine if the first player can guarantee at least a tie (or a win)
 * regardless of how the second player plays. The challenge is to simulate all
 * possible choices and see if player 1 can always secure a non-losing outcome.
 *
 * High-Level Summary:
 * ----
 * The solution uses dynamic programming (DP) to model the game. For any
 * subarray, we compute the maximum score difference the current player can
 * achieve over the other player, assuming both play optimally. The DP state
 * dp[i][j] represents the best score difference the current player can achieve
 * from nums[i..j]. The main function initializes the DP table and checks if
 * player 1's final score difference is non-negative (meaning player 1 can win
 * or tie). Time complexity is O(n^2), and space complexity is O(n^2), where n
 * is the length of nums.
 */

#include <algorithm> // Include algorithm for std::max
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to determine if Player 1 can win or tie
  bool predictTheWinner(vector<int> &nums) {
    int n = nums.size(); // Get the size of the input array

    // dp[i][j] will store the maximum score difference the current player can
    // achieve over the other player for the subarray nums[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: when i == j, only one number to pick, so the difference is
    // nums[i]
    for (int i = 0; i < n; ++i) {
      dp[i][i] = nums[i];
    }

    // Fill the DP table for all subarray lengths greater than 1
    for (int len = 2; len <= n; ++len) {
      // i is the starting index of the subarray
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1; // j is the ending index of the subarray

        // If the current player picks nums[i], the opponent will play optimally
        // on nums[i+1..j] The net gain is nums[i] - dp[i+1][j] (since
        // dp[i+1][j] is the opponent's best difference)
        int pickLeft = nums[i] - dp[i + 1][j];

        // If the current player picks nums[j], the opponent will play optimally
        // on nums[i..j-1]
        int pickRight = nums[j] - dp[i][j - 1];

        // The current player chooses the option that maximizes their score
        // difference
        dp[i][j] = std::max(pickLeft, pickRight);
      }
    }

    // If the final score difference is >= 0, player 1 can win or tie
    return dp[0][n - 1] >= 0;
  }
};
// @lc code=end
