/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is: Given a "mountain" array—where numbers first
 * increase up to a *unique* peak, then decrease after—find and return the
 * index of that mountain's peak. You are *guaranteed* that such a peak exists
 * and is not at the ends of the array. The main challenge is to do it in
 * logarithmic time, hinting strongly at binary search.
 *
 * High-Level Summary:
 * ----
 * We'll use a modified binary search method (O(log n) time, O(1) space) to
 * efficiently locate the peak index. At each step, check the mid position:
 * - If arr[mid] is less than the next element, move right (we're still on the
 *   ascending slope).
 * - Otherwise, move left (we're on/at/after the peak).
 * The binary search homes in on the highest point by always moving toward
 * the larger neighbor. The loop continues until the left and right pointers
 * meet at the peak index.
 * We modularize the solution for clarity: a helper checks the slope at each
 * index.
 */

#include <vector> // Include for std::vector
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to return the peak index in a mountain array.
  int peakIndexInMountainArray(vector<int> &arr) {
    // Initialize left and right pointers for binary search
    int left = 1; // The peak can't be at index 0, so we start at 1
    int right = arr.size() -
                2; // The peak can't be at the last index, so stop at size-2

    // Perform binary search for the peak
    while (left <= right) {
      int mid = left + (right - left) / 2; // This avoids (left+right) overflow

      if (isPeak(arr, mid)) {
        // Found the peak: arr[mid] greater than both neighbors
        return mid;
      } else if (arr[mid] < arr[mid + 1]) {
        // We are on the increasing slope (climbing up), so move right
        left = mid + 1;
      } else {
        // We are on the decreasing slope (descending down), move left
        right = mid - 1;
      }
    }
    // For a guaranteed mountain, we'll never reach here, but return left by
    // default
    return left;
  }

private:
  // Helper function to check if arr[mid] is the mountain peak
  bool isPeak(const vector<int> &arr, int mid) {
    // The peak is greater than its immediate neighbors
    return arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1];
  }
};
// @lc code=end
