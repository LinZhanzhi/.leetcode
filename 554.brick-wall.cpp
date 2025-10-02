/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a wall made up of rows of bricks, where each row can have bricks
 * of different widths, but all rows have the same total width. We want to draw
 * a vertical line from the top to the bottom of the wall such that it crosses
 * the fewest number of bricks. If the line passes exactly along the edge
 * between two bricks (not at the wall's left or right edge), it does NOT count
 * as crossing a brick. Our goal is to find the minimum number of bricks the
 * line must cross.
 *
 * High-Level Summary:
 * ----
 * The key insight is that the best place to draw the line is where the most
 * brick edges align vertically (excluding the wall's left and right edges). For
 * each row, we compute the positions of the brick edges (prefix sums, not
 * including the last edge), and count how many times each edge position occurs
 * across all rows. The answer is the total number of rows minus the maximum
 * count of any edge position (since those rows would not be crossed at that
 * position). If no edge aligns (i.e., all rows are single bricks), the answer
 * is the number of rows.
 *
 * Time Complexity: O(N * M), where N is the number of rows and M is the average
 * number of bricks per row. Space Complexity: O(K), where K is the number of
 * unique edge positions (at most sum of all bricks).
 */

#include <algorithm>     // For std::max
#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::max;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to compute the minimum number of crossed bricks
  int leastBricks(vector<vector<int>> &wall) {
    // Use long long for edge positions to avoid integer overflow
    unordered_map<long long, int> edgeCount = countEdgePositions(wall);

    // Find the maximum number of rows that share an edge position
    int maxEdges = findMaxEdgeCount(edgeCount);

    // The minimum number of crossed bricks is total rows minus maxEdges
    // If no edge aligns (maxEdges == 0), we must cross all rows
    return static_cast<int>(wall.size()) - maxEdges;
  }

private:
  // Helper function to count the number of times each edge position occurs
  // Uses long long for edge positions to handle large wall widths
  unordered_map<long long, int>
  countEdgePositions(const vector<vector<int>> &wall) {
    unordered_map<long long, int>
        edgeCount; // Maps edge position to its frequency

    // Iterate through each row of the wall
    for (const auto &row : wall) {
      long long position =
          0; // Current position from the left edge (use long long)

      // Go through all bricks in the row except the last one
      // (We don't want to consider the rightmost edge)
      for (size_t i = 0; i < row.size() - 1; ++i) {
        position += static_cast<long long>(
            row[i]); // Move to the next edge, cast to long long for safety
        edgeCount[position]++; // Count this edge position
      }
    }
    return edgeCount;
  }

  // Helper function to find the maximum edge count (most common edge position)
  // Accepts unordered_map<long long, int> to match the edgeCount type
  int findMaxEdgeCount(const unordered_map<long long, int> &edgeCount) {
    int maxEdges = 0;
    // Iterate through all edge positions to find the maximum frequency
    for (const auto &entry : edgeCount) {
      maxEdges = max(maxEdges, entry.second);
    }
    return maxEdges;
  }
};
// @lc code=end
