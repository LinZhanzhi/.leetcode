/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given four points in 2D space and need to determine if they form a
 * square. A square must have four sides of equal (positive) length and four
 * right angles. The points can be given in any order, so our solution must be
 * order-agnostic. We need to check that all sides are equal, all diagonals are
 * equal, and that no two points coincide.
 *
 * High-Level Summary:
 * ----
 * The solution computes all six pairwise squared distances between the four
 * points. For a valid square:
 *   - There must be exactly two unique distances: the side and the diagonal.
 *   - The smaller distance (side) must occur exactly four times (for the four
 * sides).
 *   - The larger distance (diagonal) must occur exactly two times (for the two
 * diagonals).
 *   - The side length must be positive (no coincident points).
 * We use a helper function to compute squared distances (to avoid
 * floating-point errors). The main function collects all distances, counts
 * their frequencies, and checks the above conditions. Time complexity: O(1)
 * (since there are always 4 points, so 6 pairs). Space complexity: O(1)
 * (constant extra space for distance counts).
 */

#include <algorithm>     // For std::sort (if needed)
#include <unordered_map> // For std::unordered_map to count distances
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Helper function to compute the squared distance between two points.
  // Using squared distance avoids floating-point precision issues and is
  // sufficient for comparison.
  int distSq(const vector<int> &a, const vector<int> &b) {
    int dx = a[0] - b[0];
    int dy = a[1] - b[1];
    return dx * dx + dy * dy;
  }

  // Main function to determine if the four points form a valid square.
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    // Store all four points in a vector for easy iteration.
    vector<vector<int>> points = {p1, p2, p3, p4};

    // Use a map to count the frequency of each unique squared distance.
    unordered_map<int, int> distCount;

    // There are 6 unique pairs among 4 points; compute all pairwise squared
    // distances.
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        int d = distSq(points[i], points[j]);
        // If two points coincide, the distance will be zero, which is invalid
        // for a square.
        if (d == 0)
          return false;
        distCount[d]++;
      }
    }

    // For a valid square, there must be exactly two unique distances:
    // - The side (appearing 4 times)
    // - The diagonal (appearing 2 times)
    if (distCount.size() != 2)
      return false;

    // Check the frequency of each distance.
    // One must occur 4 times (sides), the other 2 times (diagonals).
    bool foundFour = false, foundTwo = false;
    for (const auto &entry : distCount) {
      if (entry.second == 4)
        foundFour = true;
      else if (entry.second == 2)
        foundTwo = true;
      else
        return false; // Any other count is invalid
    }

    // Additional check: For a valid square, the diagonal's squared length must
    // be exactly twice the side's squared length (by the Pythagorean theorem
    // for a right triangle). Let's extract the two unique distances and verify
    // this relationship.
    if (foundFour && foundTwo) {
      int side = 0, diagonal = 0;
      for (const auto &entry : distCount) {
        if (entry.second == 4)
          side = entry.first; // The side's squared length
        else if (entry.second == 2)
          diagonal = entry.first; // The diagonal's squared length
      }
      // The diagonal of a square is sqrt(2) times the side, so squared:
      // diagonal^2 = 2 * side^2
      if (diagonal != 2 * side)
        return false;
    }
    // Only return true if both conditions are met.
    return foundFour && foundTwo;
  }
};
// @lc code=end
