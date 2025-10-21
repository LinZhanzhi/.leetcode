/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// Brief Digested Understanding:
// ----
// The goal is to take a list of integers and sort it in ascending order without
// using built-in sort functions. You're required to achieve O(n log n) time
// complexity (for efficiency) and minimize extra space usage. This means an
// efficient, in-place algorithm is best—think Merge Sort, Heap Sort, or Quick
// Sort (in-place variants only). The main task is to return the sorted array
// after applying the sorting algorithm.

// High-Level Summary:
// ----
// We'll use in-place Heap Sort. Heap sort builds a max-heap in linear time and
// then repeatedly removes the largest element and places it at the end of the
// array. This approach has O(n log n) time complexity, does not require
// significant extra space (sorting is done in place), and handles all inputs
// within the specified constraints. To keep things modular, we'll use helper
// functions for heapifying sub-parts of the array, and for the overall heap
// sort process. This helps explain the logic and makes it easy to trace each
// step. Space complexity is O(1) (ignoring recursive call stack for heapify
// which is O(log n)).

// @lc code=start

#include <vector> // Required to use std::vector for the nums array
using std::vector;

class Solution {
public:
  // The public function to sort the array as required by LeetCode
  vector<int> sortArray(vector<int> &nums) {
    // Call the heap sort function to sort nums in place
    heapSort(nums);
    // Return the sorted array
    return nums;
  }

private:
  // Helper function to heapify a subtree rooted at index i
  // n is the effective size of the heap we're considering
  void heapify(vector<int> &nums, int n, int i) {
    int largest = i;       // Start with the current root as largest
    int left = 2 * i + 1;  // Left child index in the heap
    int right = 2 * i + 2; // Right child index in the heap

    // If the left child exists and is greater than root, update largest
    if (left < n && nums[left] > nums[largest]) {
      largest = left;
    }

    // If the right child exists and is greater than current largest, update
    if (right < n && nums[right] > nums[largest]) {
      largest = right;
    }

    // If largest is not root, swap with largest and continue heapifying
    if (largest != i) {
      std::swap(nums[i], nums[largest]);
      // Heapify the (sub)tree affected by the swap
      heapify(nums, n, largest);
    }
    // If root was already largest, nothing to do (heap property satisfied)
  }

  // The main Heap Sort function: sorts the nums array in place
  void heapSort(vector<int> &nums) {
    int n = nums.size();

    // Step 1: Build a max heap (largest element at the root)
    // We start from the last parent, moving up to the root
    for (int i = n / 2 - 1; i >= 0; --i) {
      heapify(nums, n, i);
      // Invariant: nums[i..n-1] is heapified at each step
    }

    // Step 2: Extract elements one by one from the heap (from end to front)
    for (int i = n - 1; i > 0; --i) {
      // Swap current root (maximum) with the last element
      std::swap(nums[0], nums[i]);
      // Restore the max-heap property for the reduced heap
      heapify(nums, i, 0);
      // (Don't include nums[i] in next heapify: sorted region grows with each
      // step)
    }
    // Now, nums is fully sorted in ascending order
  }
};
// @lc code=end
