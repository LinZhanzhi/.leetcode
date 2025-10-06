/*
 * @lc app=leetcode id=624 lang=cpp
 *
 * [624] Maximum Distance in Arrays
 */

// Brief Digested Understanding:
// -----------------------------
// The problem gives us several sorted arrays and asks us to pick one number
// from each of two different arrays, then compute the absolute difference
// between those two numbers. Our goal is to find the largest possible such
// difference. Since each array is sorted, the smallest and largest numbers in
// each array are at the beginning and end, respectively. The challenge is to
// maximize the distance by picking the global minimum and maximum from
// different arrays.
//
// High-Level Summary:
// -------------------
// To solve this efficiently, we track the minimum and maximum values seen so
// far as we iterate through the arrays. For each array (after the first), we
// consider two possible distances: the difference between its maximum and the
// global minimum so far (from a different array), and the difference between
// its minimum and the global maximum so far. We update the answer with the
// largest of these. After processing each array, we update the global minimum
// and maximum. This approach ensures we always pick numbers from different
// arrays and runs in O(N) time, where N is the number of arrays. Space
// complexity is O(1) beyond the input.
//
// The code is modularized with helper functions for clarity and educational
// value.

#include <algorithm> // For std::max, std::min
#include <cstdlib>   // For std::abs
#include <vector>    // For std::vector


using std::abs;
using std::max;
using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the maximum distance
  int maxDistance(vector<vector<int>> &arrays) {
    // Edge case: If there are less than 2 arrays, no valid answer
    if (arrays.size() < 2)
      return 0;

    // Initialize global minimum and maximum using the first array
    int globalMin = getFirstElement(arrays[0]);
    int globalMax = getLastElement(arrays[0]);
    int maxDist = 0; // To keep track of the maximum distance found

    // Iterate through the rest of the arrays
    for (size_t i = 1; i < arrays.size(); ++i) {
      int currMin = getFirstElement(arrays[i]);
      int currMax = getLastElement(arrays[i]);

      // Compute possible distances by pairing current array's min/max
      // with the global max/min from previous arrays (ensuring different
      // arrays)
      int dist1 = abs(currMax - globalMin); // Current max with previous min
      int dist2 = abs(globalMax - currMin); // Previous max with current min

      // Update the maximum distance found so far
      maxDist = max(maxDist, max(dist1, dist2));

      // Update the global minimum and maximum for future iterations
      globalMin = min(globalMin, currMin);
      globalMax = max(globalMax, currMax);
    }

    return maxDist;
  }

private:
  // Helper function to get the first (smallest) element of a sorted array
  int getFirstElement(const vector<int> &arr) {
    // Since arrays are guaranteed to be non-empty and sorted,
    // the first element is the smallest
    return arr.front();
  }

  // Helper function to get the last (largest) element of a sorted array
  int getLastElement(const vector<int> &arr) {
    // Since arrays are guaranteed to be non-empty and sorted,
    // the last element is the largest
    return arr.back();
  }
};
// @lc code=end
