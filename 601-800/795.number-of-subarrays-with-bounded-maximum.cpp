/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// Brief Digested Understanding:
// ----
// This problem asks: Given an integer array, how many non-empty
// contiguous subarrays have their maximum element in a given range [left,
// right]? In other words, for each subarray, if its largest number is at least
// `left` and at most `right`, we count it. Because the array can be very large
// (up to 100,000 elements), our solution must avoid checking all subarrays
// one-by-one (which would be too slow).

// High-Level Summary:
// ----
// Instead of brute-forcing every subarray, we count the subarrays
// where the maximum is ≤ right, and subtract the subarrays where
// the maximum is < left. This uses the principle that the set of
// subarrays whose max ∈ [left, right] is exactly those whose max
// ≤ right, minus those whose max < left.
// We'll use a helper function that, for a given bound, counts all
// subarrays whose maximum ≤ bound, using a sliding window:
// For every index, as long as nums[i] ≤ bound, increment a running
// "stretch" of valid subarrays.
// The total time and space complexity is O(N) where N is nums.size(),
// making it efficient for large inputs. All logic is broken into helper
// functions for clarity and educational value.

// Required includes for using std::vector
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function: returns the number of valid subarrays for the problem
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    // The count of subarrays with max <= right
    int countRight = countBounded(nums, right);

    // The count of subarrays with max < left (i.e., with max <= left-1)
    int countLeft = countBounded(nums, left - 1);

    // Subtract: result is number whose max in [left, right]
    return countRight - countLeft;
  }

private:
  // Helper function:
  // Counts the number of contiguous subarrays where all elements are ≤ bound,
  // i.e., subarrays whose maximum value is ≤ bound.
  int countBounded(const vector<int> &nums, int bound) {
    int count = 0; // Total count of valid subarrays
    int cur = 0;   // Current length of latest valid stretch

    // Iterate through nums to build valid stretches
    for (int num : nums) {
      if (num <= bound) {
        // Extend the current valid stretch
        cur++;
        count += cur;
        // Each time, cur new subarrays end at this position
      } else {
        // We hit a number > bound, so reset the current stretch
        cur = 0;
      }
    }
    return count;
  }
};
// @lc code=end
