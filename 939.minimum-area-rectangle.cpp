/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// Brief Digested Understanding:
// ----
// This problem asks us to find the smallest possible area of an axis-aligned
// rectangle that can be formed from a set of unique 2D points. Sides of the
// rectangle must run parallel to the axes (no rotating allowed). We are to
// return 0 if no such rectangle exists. The main challenge is efficiently
// searching the points' set for rectangle candidates, given the potentially
// large input size.
//
// High-Level Summary:
// ----
// The approach leverages hashing for quick point existence lookup.
// - For every pair of vertical lines (i.e., for all distinct x1, x2),
//   track and compare their common y-coordinates, since vertical sides
//   of an axis-aligned rectangle must share the same y-values for the top
//   and bottom edges.
// - For each pair of columns, scan all y, and for each matching (y1, y2)
//   on both columns, form the rectangle, compute the area, and check if
//   it's the minimum.
// - Uses an unordered_map<int, vector<int>> to group all y-coordinates on each
// x. The time complexity is O(N^2) in practice (since for up to 500 points
// there are O(N^2) x-pairs), and space complexity is O(N), as we store the
// points in maps. This is efficient enough for the constraints.

// Required C++ library includes
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::min;
using std::pair;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
  // Helper function to construct a map from each x coordinate
  // to all associated y coordinates for efficient lookup.
  unordered_map<int, vector<int>>
  buildXToYMap(const vector<vector<int>> &points) {
    unordered_map<int, vector<int>> xToY;
    for (const auto &point : points) {
      int x = point[0];
      int y = point[1];
      xToY[x].push_back(y);
    }
    return xToY; // Each x key maps to all y's at that x
  }

  // Main function to compute the minimum area rectangle
  int minAreaRect(vector<vector<int>> &points) {
    // Build a quick index: x-coordinate -> all y's at that x
    unordered_map<int, vector<int>> xToY = buildXToYMap(points);

    // To quickly check if a point exists, put all points in a set.
    unordered_set<long long> pointSet;
    for (const auto &pt : points) {
      // Use a long long to avoid collisions: (x << 32) | y
      pointSet.insert((static_cast<long long>(pt[0]) << 32) | pt[1]);
    }

    int minArea = INT_MAX; // Start with "impossible" max area

    // Store all unique x-coordinates for outer loop
    vector<int> xCoords;
    for (const auto &entry : xToY) {
      xCoords.push_back(entry.first);
    }

    // Iterate over all pairs of x's (vertical columns)
    for (int i = 0; i < xCoords.size(); ++i) {
      for (int j = i + 1; j < xCoords.size(); ++j) {
        int x1 = xCoords[i];
        int x2 = xCoords[j];
        // Find all "shared y" between x1 and x2: rectangle sides
        // For quick lookup, use unordered_set for first x's y-values
        unordered_set<int> ySet(xToY[x1].begin(), xToY[x1].end());
        vector<int> commonY; // Holds y-values on both columns

        for (int y : xToY[x2]) {
          if (ySet.count(y)) {
            commonY.push_back(y);
          }
        }
        // If there are at least two y's, rectangles are possible
        // Try all pairs of shared y's to get rectangles
        if (commonY.size() >= 2) {
          // Sort the y's to process in order
          std::sort(commonY.begin(), commonY.end());
          // For every pair of common y's, (y1, y2),
          // area is |x2 - x1| * |y2 - y1|.
          for (int m = 1; m < commonY.size(); ++m) {
            // Previous and current y form the potential opposite corners
            int y1 = commonY[m - 1];
            int y2 = commonY[m];
            int area = abs(x2 - x1) * abs(y2 - y1);
            if (area < minArea) {
              minArea = area;
            }
          }
        }
      }
    }
    // If no rectangle found, return 0
    return (minArea == INT_MAX) ? 0 : minArea;
  }
};
// @lc code=end
