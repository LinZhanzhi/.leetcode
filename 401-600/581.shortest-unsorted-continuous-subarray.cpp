/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given an array of integers, we want to find the shortest continuous subarray
 * that, if sorted, would make the entire array sorted in non-decreasing order.
 * If the array is already sorted, the answer is 0. Otherwise, we need to
 * identify the smallest window (subarray) that, when sorted, fixes the whole
 * array.
 *
 * High-Level Summary:
 * ----
 * The solution scans the array from both left and right to find the boundaries
 * of the unsorted subarray. We track the maximum value seen so far from the
 * left and the minimum value seen so far from the right. If a number is less
 * than the running maximum (from the left), it is out of order and marks a
 * possible right boundary. If a number is greater than the running minimum
 * (from the right), it is out of order and marks a possible left boundary.
 * The final answer is the length between these two boundaries.
 *
 * Time Complexity: O(n), where n is the length of the array.
 * Space Complexity: O(1), as we use only a few variables for tracking.
 */

#include <algorithm> // Include algorithm for std::min and std::max
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the length of the shortest unsorted subarray
  int findUnsortedSubarray(vector<int> &nums) {
    // Helper function to find the left boundary of the unsorted subarray
    int left = findLeftBoundary(nums);
    // Helper function to find the right boundary of the unsorted subarray
    int right = findRightBoundary(nums);

    // If the array is already sorted, left will be -1 and right will be -1
    if (left == -1) {
      return 0;
    }
    // The length of the subarray is right - left + 1
    return right - left + 1;
  }

private:
  // Helper function to find the leftmost index where the array is out of order
  int findLeftBoundary(const vector<int> &nums) {
    int n = nums.size();
    int max_seen = nums[0]; // Track the maximum value seen so far from the left
    int right = -1; // Initialize right boundary as -1 (no unsorted part yet)

    // Traverse from left to right
    for (int i = 1; i < n; ++i) {
      // If current number is less than the max seen so far, it's out of order
      if (nums[i] < max_seen) {
        right = i; // Update right boundary
      } else {
        // Otherwise, update the max seen so far
        max_seen = nums[i];
      }
    }
    // If right is still -1, the array is sorted
    if (right == -1)
      return -1;

    // Now, find the left boundary by scanning from the start
    int min_seen =
        nums[n - 1]; // Track the minimum value seen so far from the right
    int left = -1;   // Initialize left boundary as -1

    // Traverse from right to left
    for (int i = n - 2; i >= 0; --i) {
      // If current number is greater than the min seen so far, it's out of
      // order
      if (nums[i] > min_seen) {
        left = i; // Update left boundary
      } else {
        // Otherwise, update the min seen so far
        min_seen = nums[i];
      }
    }
    // Return the left boundary found
    return left;
  }

  // Helper function to find the rightmost index where the array is out of order
  int findRightBoundary(const vector<int> &nums) {
    int n = nums.size();
    int max_seen = nums[0]; // Track the maximum value seen so far from the left
    int right = -1;         // Initialize right boundary as -1

    // Traverse from left to right
    for (int i = 1; i < n; ++i) {
      // If current number is less than the max seen so far, it's out of order
      if (nums[i] < max_seen) {
        right = i; // Update right boundary
      } else {
        // Otherwise, update the max seen so far
        max_seen = nums[i];
      }
    }
    // Return the right boundary found
    return right;
  }
};
// @lc code=end
