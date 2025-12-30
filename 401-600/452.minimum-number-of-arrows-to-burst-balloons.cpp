/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a set of balloons, each represented by a horizontal interval on
 * the x-axis. An arrow shot at a specific x-coordinate will burst all balloons
 * whose intervals include that x. The goal is to find the minimum number of
 * arrows needed to burst all balloons, i.e., to cover all intervals with as few
 * points as possible. This is a classic interval covering problem, where we
 * want to minimize the number of points (arrows) that intersect all intervals
 * (balloons).
 *
 * High-Level Summary:
 * ----
 * The optimal approach is greedy:
 *   - First, sort all balloon intervals by their ending x-coordinate.
 *   - Then, iterate through the sorted intervals, always shooting an arrow at
 * the end of the current interval if it is not already covered by a previous
 * arrow.
 *   - Each time we shoot an arrow, we update the position and continue,
 * skipping all intervals already covered by the last arrow.
 *   - This ensures we use the fewest arrows possible.
 * Time Complexity: O(N log N) due to sorting, where N is the number of
 * balloons. Space Complexity: O(1) extra space (ignoring the sort, which may
 * use O(N) depending on implementation).
 */

#include <algorithm> // For std::sort
#include <vector>    // For std::vector

using std::vector;

class Solution {
public:
  // Main function to find the minimum number of arrows needed to burst all
  // balloons
  int findMinArrowShots(vector<vector<int>> &points) {
    // Edge case: If there are no balloons, no arrows are needed
    if (points.empty())
      return 0;

    // Sort the intervals (balloons) by their end coordinate in ascending order
    sortIntervalsByEnd(points);

    // Initialize the count of arrows to 1 (at least one arrow is needed)
    int arrows = 1;
    // The position of the last arrow shot (initialized to the end of the first
    // interval)
    int lastArrowPos = points[0][1];

    // Iterate through the sorted intervals starting from the second balloon
    for (int i = 1; i < points.size(); ++i) {
      // If the current balloon starts after the last arrow position,
      // it means the previous arrow cannot burst this balloon
      if (points[i][0] > lastArrowPos) {
        // Shoot a new arrow at the end of the current balloon
        ++arrows;
        lastArrowPos = points[i][1];
      }
      // If the current balloon starts before or at the last arrow position,
      // it is already burst by the previous arrow, so we do nothing
    }

    // Return the total number of arrows needed
    return arrows;
  }

private:
  // Helper function to sort the intervals by their end coordinate
  void sortIntervalsByEnd(vector<vector<int>> &intervals) {
    // Use a lambda function to sort by the second element (end) of each
    // interval
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &a, const vector<int> &b) {
                // Sort by end coordinate in ascending order
                return a[1] < b[1];
              });
  }
};
// @lc code=end
