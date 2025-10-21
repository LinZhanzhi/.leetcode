/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// Brief Digested Understanding:
// ----
// Given an array of integers, for each element you can add or subtract a fixed
// value k. After modifying every element this way (choosing +k or -k for each),
// you want to make the maximum and minimum in the final array as close as
// possible. The problem thus asks for the smallest possible difference between
// the largest and smallest elements you can achieve after these operations are
// applied. Key insights: The difference can never be made negative; the overall
// approach is to try to squeeze the original range as much as possible by
// smartly assigning either +k or -k to each element.

// High-Level Summary:
// ----
// The optimal approach is to first sort the array to analyze contiguous
// elements. Without changing, the score (range) is max - min. After the
// transformation, intuitively, increasing smaller elements and decreasing
// larger elements with +k or -k, we can "split" the array: we consider for each
// possible split, making the left part increased by k and the right by -k (or
// vice versa). For any such split, the new min and max values are either at the
// endpoints or at the split boundary. We check every possible split and choose
// the configuration with the minimum range. Time complexity: O(n log n) for
// sorting, then O(n) for processing splits. Space complexity: O(1) extra
// (in-place sort). We modularize with helper functions for computing the new
// min and new max values for clarity.

// Include necessary header
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  // Helper function to get new possible minimum after the split
  int getNewMin(const vector<int> &nums, int k, int i) {
    // Returns the minimum of:
    // - the new minimum on increasing the first i+1 elements by k (nums[0] + k)
    // - the new minimum on decreasing the rest by k (nums[i+1] - k)
    return std::min(nums[0] + k, nums[i + 1] - k);
  }

  // Helper function to get new possible maximum after the split
  int getNewMax(const vector<int> &nums, int k, int i) {
    // Returns the maximum of:
    // - the new maximum on increasing the first i+1 elements by k (nums[i] + k)
    // - the new maximum on decreasing the rest by k (nums.back() - k)
    return std::max(nums[i] + k, nums.back() - k);
  }

  int smallestRangeII(vector<int> &nums, int k) {
    // Edge case: If the array has only one element, range is always 0.
    if (nums.size() <= 1) {
      return 0;
    }

    // Sort the numbers for easier analysis of contiguous splits
    std::sort(nums.begin(), nums.end());

    // Initial answer: current range without any change
    int n = nums.size();
    int answer = nums.back() - nums.front();

    // Now, try every split (from 0 to n-2)
    // That means index i: elements nums[0..i] will be +k, nums[i+1..n-1] will
    // be -k
    for (int i = 0; i < n - 1; ++i) {
      // Compute potential new min and new max after this split
      int newMin = getNewMin(nums, k, i);
      int newMax = getNewMax(nums, k, i);

      // Check if this configuration gives a smaller range
      int currentRange = newMax - newMin;
      // Update answer if this split yields a smaller range
      if (currentRange < answer) {
        answer = currentRange;
      }
    }
    return answer;
  }
};
// @lc code=end
