/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is to select k elements from a sorted array that are
 * closest to a target value x. "Closeness" is defined by absolute difference,
 * and if two numbers are equally close, the smaller number should be chosen.
 * The result must be sorted in ascending order. The sorted nature of the array
 * is crucial for an efficient solution.
 *
 * High-Level Summary:
 * ----
 * We use a binary search to find the leftmost starting index of a window of
 * size k such that the k elements in this window are the closest to x. The key
 * is to compare the distances at the window's boundaries, but to handle
 * tie-breaking correctly (when distances are equal, prefer the rightmost
 * window, i.e., the window with larger elements). This is done by adjusting the
 * binary search comparison: if the left boundary is equally close as the right,
 * we move the window to the right. The solution is modularized into helper
 * functions for clarity. The time complexity is O(log(n-k) + k), and space
 * complexity is O(k) for the output.
 */

#include <cstdlib> // For std::abs
#include <vector>  // For std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find k closest elements to x in arr
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    // Find the leftmost index of the window of size k using binary search
    int left = findLeftBoundary(arr, k, x);
    // Extract the k elements starting from the found left index
    return extractWindow(arr, left, k);
  }

private:
  // Helper function to perform binary search for the left boundary
  // This version handles tie-breaking by preferring the window with larger
  // elements
  int findLeftBoundary(const vector<int> &arr, int k, int x) {
    int n = arr.size();
    int left = 0;
    int right = n - k; // The window of size k must fit in arr

    // Binary search to find the smallest left such that
    // arr[left]...arr[left+k-1] is the best window
    while (left < right) {
      int mid = left + (right - left) / 2;
      // Calculate the absolute difference between x and the window's boundaries
      int distLeft = std::abs(x - arr[mid]);
      int distRight = std::abs(x - arr[mid + k]);
      // If the left boundary is closer, or equally close but smaller, keep/move
      // left If the right boundary is closer or equally close (and larger),
      // move window right To match the problem's tie-breaking (prefer larger
      // numbers when distances are equal), we move right when distLeft <=
      // distRight
      if (distLeft < distRight) {
        // If the left boundary is strictly closer, keep/move left (search left
        // half)
        right = mid;
      } else if (distLeft > distRight) {
        // If the right boundary is strictly closer, move left boundary right
        // (search right half)
        left = mid + 1;
      } else {
        // distLeft == distRight, need more checking as per custom tie-breaking
        // We want to find the next element in arr[mid, right] that is larger
        // than arr[mid]
        // Use std::upper_bound to find the first index in [mid+1, right] where
        // arr[idx] > arr[mid] std::upper_bound returns an iterator to the first
        // element greater than arr[mid] We need to search in arr.begin() + (mid
        // + 1) to arr.begin() + (right + 1)
        auto upper =
            std::upper_bound(arr.begin() + mid + k, arr.end(), arr[mid + k]);
        int largerIdx =
            (upper != arr.end()) ? std::distance(arr.begin(), upper) : -1;
        if (largerIdx == -1) {
          // All elements in arr[mid, right] are equal to arr[mid], so keep/move
          // left
          right = mid;
        } else {
          // Compare the distance of arr[largerIdx] to x
          int distLarger = std::abs(x - arr[largerIdx]);
          if (distLarger < distLeft) {
            // arr[largerIdx] is closer to x, so move left boundary right
            left = mid + 1;
          } else {
            // arr[mid] is closer or equally close, so keep/move left
            right = mid;
          }
        }
      }
    }
    // left is now the start index of the optimal window
    return left;
  }

  // Helper function to extract the window of k elements starting at left
  vector<int> extractWindow(const vector<int> &arr, int left, int k) {
    // Create a vector containing arr[left] to arr[left + k - 1]
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
  }
};
// @lc code=end
