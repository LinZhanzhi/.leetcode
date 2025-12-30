/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We have a large m x n matrix, all initialized to 0. Each time we call flip(),
 * we must randomly pick a cell (i, j) that is still 0, flip it to 1, and return
 * its coordinates. All available (0-valued) cells must be equally likely to be
 * chosen. The reset() function sets all cells back to 0. The challenge is to do
 * this efficiently, without storing the entire matrix or making too many random
 * calls.
 *
 * High-Level Summary:
 * ----
 * To efficiently support random flipping and resetting, we treat the matrix as
 * a flat array of size m*n. We use a hash map to simulate a shuffle: each time
 * we flip, we randomly pick an available index, and map it to the last
 * available index, reducing the available pool by one. This is similar to the
 * "Fisher-Yates shuffle" but done lazily. This approach ensures O(1) time and
 * space per flip/reset (amortized), and avoids storing the whole matrix. The
 * hash map only stores mappings for indices that have been swapped.
 *
 * Time Complexity:
 *   - flip(): O(1) expected time per call.
 *   - reset(): O(1) time.
 * Space Complexity:
 *   - O(k), where k is the number of flips since last reset (at most m*n).
 */

#include <cstdlib>       // For rand() and srand().
#include <unordered_map> // For std::unordered_map to store index mappings.
#include <vector>        // For std::vector to return coordinates.

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
private:
  int m_rows; // Number of rows in the matrix.
  int m_cols; // Number of columns in the matrix.
  int total;  // Number of available (unflipped) cells remaining.
  unordered_map<int, int>
      mapping; // Maps a chosen index to its actual value if swapped.

  // Helper function to convert a flat index to (row, col) coordinates.
  vector<int> indexToCoord(int idx) {
    // idx / m_cols gives the row, idx % m_cols gives the column.
    return {idx / m_cols, idx % m_cols};
  }

public:
  // Constructor: Initializes the matrix size and resets state.
  Solution(int m, int n) : m_rows(m), m_cols(n), total(m * n) {
    // No need to initialize the mapping here; it will be empty.
  }

  // Randomly flips a 0 to 1 and returns its coordinates.
  vector<int> flip() {
    // Pick a random index from the available pool [0, total-1].
    int randIdx = rand() % total;

    // Find the actual index to flip: if randIdx has been mapped, use its
    // mapping; else use randIdx itself.
    int actualIdx = mapping.count(randIdx) ? mapping[randIdx] : randIdx;

    // Decrease the pool of available cells.
    --total;

    // Map randIdx to the last available index (if it has been mapped, use its
    // mapping; else use total). This ensures that future flips won't pick the
    // same cell.
    int lastIdx = mapping.count(total) ? mapping[total] : total;
    mapping[randIdx] = lastIdx;

    // Return the 2D coordinates of the flipped cell.
    return indexToCoord(actualIdx);
  }

  // Resets all cells to 0.
  void reset() {
    // Reset the available pool and clear the mapping.
    total = m_rows * m_cols;
    mapping.clear();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
