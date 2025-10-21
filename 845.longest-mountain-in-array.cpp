/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start

#include <algorithm> // Include for std::max
#include <vector>    // Include vector header for std::vector

using std::max;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding the longest "mountain" in a 1D array.
 * A mountain is a contiguous subarray with at least three elements, where
 * numbers strictly increase up to a peak, and then strictly decrease after.
 * We're asked to return the length of the longest such mountain, or 0 if none
 * exist. The crux is properly identifying valid mountain shapes and efficiently
 * measuring and comparing their lengths.
 *
 * High-Level Summary:
 * ----
 * We'll use a single pass (O(n) time) and constant (O(1)) additional space.
 * For each possible peak (an element that is larger than both its neighbors),
 * we expand left and right to find the maximum stretch of strictly increasing
 * and then decreasing values — thus, the mountain's full length.
 * We track and return the largest such length found. The solution is
 * modularized: a helper function checks for a mountain at a given peak and
 * measures its length. Edge cases (like flat areas or too-short arrays) are
 * handled up front.
 */

class Solution {
public:
  // The main function to find the length of the longest mountain in the array.
  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    int longest = 0;

    // The minimum size for a mountain is 3, so skip if the array is too small.
    if (n < 3) {
      return 0;
    }

    // Start from the second element and go to the second-to-last.
    // This is because a valid peak can't be at the very ends.
    for (int i = 1; i < n - 1; ++i) {
      // Check if arr[i] is a valid mountain peak.
      if (isPeak(arr, i)) {
        int mountLen = expandFromPeak(arr, i, n);
        longest = max(longest, mountLen);

        // Optimization: Skip processing indices that belong to this mountain
        // (they can't be peaks). Advance i to the end of the current mountain's
        // descent.
        i = mountainEndIndex(arr, i, n);
      }
    }
    return longest;
  }

private:
  // Helper to check whether arr[i] is a "peak" of a mountain (greater than both
  // neighbors)
  bool isPeak(const vector<int> &arr, int i) {
    // Explanation:
    // A valid peak must be strictly greater than both immediate neighbors.
    // Specifically, arr[i-1] < arr[i] > arr[i+1].
    return arr[i - 1] < arr[i] && arr[i] > arr[i + 1];
  }

  // Helper to expand from peak index i and return the length of the full
  // mountain.
  int expandFromPeak(const vector<int> &arr, int i, int n) {
    int left = i;
    int right = i;

    // Expand leftward as long as strictly increasing
    while (left > 0 && arr[left - 1] < arr[left]) {
      left--;
    }

    // Expand rightward as long as strictly decreasing
    while (right + 1 < n && arr[right] > arr[right + 1]) {
      right++;
    }

    // The length of the current mountain is (right - left + 1)
    // Only peaks with both up and down slopes reach here due to isPeak check.
    return right - left + 1;
  }

  // Helper to return the last index of this mountain decreasing slope, so main
  // loop can skip unnecessary indices.
  int mountainEndIndex(const vector<int> &arr, int i, int n) {
    int right = i;
    // Continue moving right as long as we're on a descending slope.
    while (right + 1 < n && arr[right] > arr[right + 1]) {
      right++;
    }
    return right;
  }
};
// @lc code=end
