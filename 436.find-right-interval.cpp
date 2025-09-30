/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// Brief, Digested Understanding:
//
// The problem asks us, for each interval in a list, to find the "right
// interval": another interval whose start is the smallest possible value that
// is greater than or equal to the current interval's end. If no such interval
// exists, we return -1 for that position. Each interval's start is unique,
// which allows us to efficiently search for the right interval.
//
// High-Level Summary:
//
// The main idea is to map each interval's start value to its original index,
// then sort these (start, index) pairs. For each interval, we use binary search
// to quickly find the smallest start that is >= the current interval's end.
// This is efficient because sorting and binary search both have good time
// complexity. The overall time complexity is O(n log n), where n is the number
// of intervals, and the space complexity is O(n) for storing the mapping and
// result.
//
// We use C++ STL features such as vector, pair, and lower_bound for efficient
// implementation.

// @lc code=start
#include <algorithm> // For std::sort and std::lower_bound
#include <utility>   // For std::pair
#include <vector>    // For std::vector

using std::lower_bound;
using std::pair;
using std::sort;
using std::vector;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size(); // Number of intervals
    // This vector will store pairs of (start value, original index)
    vector<pair<int, int>> starts;
    for (int i = 0; i < n; ++i) {
      // Store the start value and its original index
      starts.push_back({intervals[i][0], i});
    }
    // Sort the starts vector by start value so we can binary search it
    sort(starts.begin(), starts.end());

    // Prepare the result vector, initialized to -1 (meaning "no right interval
    // found")
    vector<int> result(n, -1);

    // For each interval, find the right interval using binary search
    for (int i = 0; i < n; ++i) {
      int target = intervals[i][1]; // The end value of the current interval
      // Use lower_bound to find the first start >= target
      // lower_bound returns an iterator to the first element not less than
      // target
      auto it =
          lower_bound(starts.begin(), starts.end(), pair<int, int>{target, 0}
                      // We only care about the start value for comparison
          );
      if (it != starts.end()) {
        // If we found such an interval, store its original index in the result
        result[i] = it->second;
      }
      // If not found, result[i] remains -1
    }
    return result;
  }
};
// @lc code=end
