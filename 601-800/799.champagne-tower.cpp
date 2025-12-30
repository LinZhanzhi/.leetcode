/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// Brief Digested Understanding:
// ----
// At heart, this problem is about simulating how poured champagne spreads
// through a triangular stack of glasses, where each glass can hold only 1 cup.
// Any excess overflows equally to the two glasses below. We're asked how full a
// specific glass (at a row and column index) is, after pouring some number of
// cups into the top glass. The process is discrete: overflow is recursively
// split down the "pyramid," and we're interested in how much ends up in a
// target glass—never more than 1 cup, possibly less. All indices are
// zero-based, so row 0 is the top of the pyramid.

// High-Level Summary:
// ----
// We'll solve this by simulating the pouring process row by row. We'll use a
// 2D array (or vector of vectors) to track the amount in each glass. For every
// glass, if it overflows (more than 1 unit), its excess is divided equally and
// spilled to the two glasses below. We'll repeat this for each row until we
// reach the target row. As the constraints are modest (rows < 100), we can
// afford this simulation. The answer is the minimum of the glass's contents and
// 1.0, since a glass can't hold more than full. Time and space complexity are
// both O(N^2) for N = 100.

// @lc code=start
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
  // Main function to simulate the champagne tower and return glass fullness
  double champagneTower(int poured, int query_row, int query_glass) {
    // The problem specifies that the 100th row is the max, so we can allocate a
    // fixed size Create the tower simulation: rows are increasing, each row r
    // has r+1 glasses Each glass stores the current amount poured into it
    // (could be >1 before overflow)
    vector<vector<double>> tower(query_row + 2,
                                 vector<double>(query_row + 2, 0.0));
    // Why +2? To avoid index out of range when accessing lower row glasses

    // Start by pouring all champagne into the top glass (row 0, glass 0)
    tower[0][0] = poured;

    // Iterate row by row to propagate the overflow down the pyramid
    for (int r = 0; r <= query_row; ++r) {
      for (int g = 0; g <= r; ++g) {
        // If the current glass is overflowing, pour the excess down
        double overflow = (tower[r][g] - 1.0) / 2.0;
        if (overflow > 0) {
          // Each lower glass gets half the excess
          tower[r + 1][g] += overflow;     // Left glass below
          tower[r + 1][g + 1] += overflow; // Right glass below
          // Note: this works even if r+1 == query_row+1, because we
          // over-allocate
        }
      }
    }
    // The actual fullness can't exceed 1, as the glass will never hold more
    // than full
    return min(1.0, tower[query_row][query_glass]);
  }
};
// @lc code=end
