/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// Brief Digested Understanding:
// ----
// This problem asks you to maximize the total points earned by removing numbers
// from the array, where picking a number x gives you x points (times the number
// of occurrences) but forces you to also remove all instances of (x-1) and
// (x+1). The key is that taking a number blocks taking its neighbors. At its
// core, this is a variant of the classic "House Robber" problem, but instead of
// houses in a row, we treat each unique value as a "house," and their adjacency
// is determined by integer values (not their indexes in the original array).

// High-Level Summary:
// ----
// The approach is to first count the total points available from each unique
// value (by summing up all repetitions). Then, for all possible numbers from
// the smallest to the largest in nums, use dynamic programming to decide for
// each value whether to "take it" (and thus skip its immediate neighbors) or
// "skip it" (and allow for possibly taking the neighbors). We build a DP table
// similar to House Robber: for each value v, dp[v] = max(dp[v-1], dp[v-2] +
// total_points_for_v). Complexity is O(N + M), where N is the length of nums
// and M is the maximum unique value, with O(M) space for the DP array.

// @lc code=start

#include <algorithm>     // For std::max and std::min/max_element
#include <unordered_map> // For counting occurrences of numbers
#include <vector>        // To use std::vector for input/output and DP arrays

using std::unordered_map;
using std::vector;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    // Handle empty case up-front for safety
    if (nums.empty())
      return 0;

    // Helper: Compute frequency map and value range
    int minVal = nums[0], maxVal = nums[0];
    unordered_map<int, int> numCount;
    for (int num : nums) {
      numCount[num] += 1;             // Count occurrences of each number
      minVal = std::min(minVal, num); // Track min value in input
      maxVal = std::max(maxVal, num); // Track max value in input
    }

    // Helper: Construct "earned" array: earned[v] = total points from v
    // This allows us to treat each unique number as an "indexable house"
    vector<int> earned(maxVal + 1, 0);
    for (auto &pair : numCount) {
      int value = pair.first;
      int count = pair.second;
      earned[value] = value * count; // All occurrences' points together
    }

    // Helper function: Dynamic Programming solution (House Robber style)
    // For each possible integer value between minVal and maxVal, we decide:
    //   - Take it: Add its points to dp[i-2], skip immediate neighbors.
    //   - Skip it: Carry forward dp[i-1].
    // We use an array where dp[i] represents the max points to be earned
    // considering all values up to i.
    int dpPrevPrev = 0; // dp[i-2], initial state (before any value)
    int dpPrev = 0;     // dp[i-1], initial state (before minVal - 1)
    for (int val = minVal; val <= maxVal; ++val) {
      // If earned[val] is zero, we simply can't take "val" (so, skip)
      int take = dpPrevPrev + earned[val]; // Pick current value, add to dp[i-2]
      int skip = dpPrev;                   // Skip current value
      int curr = std::max(take, skip); // Optimal substructure: best of the two
      // Shift DP window for next iteration
      dpPrevPrev = dpPrev;
      dpPrev = curr;
    }
    // dpPrev now holds the answer for [minVal...maxVal]
    return dpPrev;
  }
};

// @lc code=end
