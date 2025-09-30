/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the minimum number of intervals to remove from a
 * list so that the remaining intervals do not overlap. Two intervals are
 * non-overlapping if the end of one is less than or equal to the start of the
 * next. Our goal is to keep as many non-overlapping intervals as possible,
 * which means we want to remove the fewest intervals necessary.
 *
 * High-Level Summary:
 * ----
 * The optimal approach is a greedy algorithm:
 * 1. Sort the intervals by their end time (ascending).
 * 2. Iterate through the sorted intervals, always keeping track of the end of
 * the last interval we kept.
 * 3. If the current interval starts before the end of the last kept interval,
 * it overlaps and must be removed.
 * 4. Otherwise, update the end to the current interval's end.
 * The number of removals is the total number of intervals minus the count of
 * non-overlapping intervals we can keep.
 *
 * Time Complexity: O(n log n) due to sorting, where n is the number of
 * intervals. Space Complexity: O(1) extra space (ignoring the space for sorting
 * if in-place).
 */

#include <algorithm> // Include algorithm for std::sort
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // Edge case: If there are 0 or 1 intervals, no removals are needed.
    if (intervals.size() <= 1)
      return 0;

    // Sort intervals by their end time in ascending order.
    // This allows us to always pick the interval that ends earliest,
    // maximizing the number of non-overlapping intervals we can keep.
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1]; // Compare by end time
              });

    int countNonOverlap = 1;       // At least one interval can always be kept
    int lastEnd = intervals[0][1]; // End time of the last kept interval

    // Iterate through the rest of the intervals
    for (int i = 1; i < intervals.size(); ++i) {
      // If the current interval starts after or at the end of the last kept
      // interval, it does not overlap and can be kept.
      if (intervals[i][0] >= lastEnd) {
        ++countNonOverlap;         // Keep this interval
        lastEnd = intervals[i][1]; // Update the end time
      }
      // If it overlaps (starts before lastEnd), we skip it (i.e., remove it).
      // No action needed, just don't update countNonOverlap or lastEnd.
    }

    // The minimum number of removals is total intervals minus the number we can
    // keep.
    return intervals.size() - countNonOverlap;
  }
};
// @lc code=end
