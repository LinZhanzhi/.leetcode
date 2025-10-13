/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    // Helper function to check if a position is within the board boundaries
    bool isValid(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    double knightProbability(int n, int k, int row, int column) {
        // All 8 possible moves for a knight
        const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        // dp[i][j]: probability of being at (i, j) after current number of moves
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0; // Start with probability 1 at the initial position

        // Iterate for each move
        for (int step = 0; step < k; ++step) {
            // Temporary DP table for the next step
            vector<vector<double>> next_dp(n, vector<double>(n, 0.0));
            // For each cell on the board
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // If the current cell has a non-zero probability
                    if (dp[i][j] > 0) {
                        // Try all 8 knight moves
                        for (int d = 0; d < 8; ++d) {
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            // If the new position is valid, add the probability
                            if (isValid(n, ni, nj)) {
                                // Each move is equally likely (1/8)
                                next_dp[ni][nj] += dp[i][j] / 8.0;
                            }
                        }
                    }
                }
            }
            // Move to the next step
            dp = std::move(next_dp);
        }

        // Sum the probabilities of all positions on the board after k moves
        double total = 0.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                total += dp[i][j];
            }
        }
        return total;
    }
};
// @lc code=end
