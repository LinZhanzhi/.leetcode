/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the kth largest element in an array of integers.
 * This means, if we sorted the array in descending order, the element at index
 * k-1 (0-based) would be our answer. However, we are challenged to do this
 * without sorting the entire array, which can be inefficient for large inputs.
 * The goal is to efficiently select the kth largest value, not necessarily
 * unique, from the array.
 *
 * High-Level Summary:
 * ----
 * We use the Quickselect algorithm, which is a selection algorithm to find the
 * kth smallest or largest element in an unordered list. It is related to
 * Quicksort but only partially sorts the array. The algorithm works by
 * partitioning the array around a pivot such that elements greater than the
 * pivot are on one side and smaller on the other. We then recursively search
 * the side that contains the kth largest element. This approach has an average
 * time complexity of O(n) and space complexity of O(1) (in-place).
 */

#include <cstdlib> // Include cstdlib for rand()
#include <vector>  // Include vector for using std::vector

using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // Main function to find the kth largest element in the array
  int findKthLargest(vector<int> &nums, int k) {
    // The kth largest is the (n - k)th smallest in 0-based index
    int n = nums.size();
    int target = n - k;
    return quickselect(nums, 0, n - 1, target);
  }

private:
  // Quickselect helper function to find the kth smallest element in
  // nums[left...right]
  int quickselect(vector<int> &nums, int left, int right, int k_smallest) {
    // If the list contains only one element, return that element
    if (left == right) {
      return nums[left];
    }

    // Randomly select a pivot index between left and right
    int pivot_index = left + rand() % (right - left + 1);

    // Partition the array and get the final position of the pivot
    pivot_index = partition(nums, left, right, pivot_index);

    // If the pivot is at the kth smallest position, return its value
    if (k_smallest == pivot_index) {
      return nums[k_smallest];
    }
    // If the kth smallest is in the left part, recurse on the left
    else if (k_smallest < pivot_index) {
      return quickselect(nums, left, pivot_index - 1, k_smallest);
    }
    // Otherwise, recurse on the right part
    else {
      return quickselect(nums, pivot_index + 1, right, k_smallest);
    }
  }

  // Partition function similar to that used in Quicksort
  // It moves all elements less than the pivot to the left,
  // and all elements greater to the right, and returns the final index of the
  // pivot
  int partition(vector<int> &nums, int left, int right, int pivot_index) {
    int pivot_value = nums[pivot_index];
    // Move pivot to the end temporarily
    std::swap(nums[pivot_index], nums[right]);
    int store_index = left;

    // Move all elements less than pivot_value to the left
    for (int i = left; i < right; ++i) {
      if (nums[i] < pivot_value) {
        std::swap(nums[store_index], nums[i]);
        ++store_index;
      }
    }
    // Move pivot to its final place
    std::swap(nums[store_index], nums[right]);
    return store_index;
  }
};
// @lc code=end
