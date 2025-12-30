/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// Brief Digested Understanding:
// ----
// This problem is about checking whether every global inversion (an
// out-of-order pair in the permutation) is also a local inversion (where two
// adjacent elements are swapped). In other words, the number of global
// inversions should be exactly equal to the number of local inversions. If
// there exists a global inversion that is not also local (i.e., out-of-order
// numbers that are two or more indices apart), the answer should be false. This
// boils down to verifying that for any position, no element is too far from its
// true place in the sorted order.
//
// Key constraints: The input is always a permutation of [0...n-1]; nums is
// unique; the array may be large.

// High-Level Summary:
// ----
// The main algorithmic insight is that every local inversion is also a global
// inversion, but not every global inversion is local. So, for the answer to be
// true, there must not be any global inversion that is not local. This can be
// checked by making sure that nums[i] is not more than one position away from
// its sorted index, i.e., for all i, abs(nums[i] - i) <= 1.
//
// Alternatively, an O(n) approach is to track the minimum element to the right
// of each index (for i+2, i+3, etc.), or simply check for cases where an
// element nums[j] (with j ≥ i+2) is less than nums[i].
// In this modular implementation, to maximize clarity for beginners, we'll use
// the direct index-distance check. This gives O(n) time and O(1) space
// complexity, with a simple traversal.
//
// We'll break out the key check into a helper function for learning clarity.

#include <cstdlib> // To use std::abs for absolute value calculation.
#include <vector>  // To use std::vector for the nums array.

using std::vector;

// @lc code=start
class Solution {
public:
  // The main function that determines if all global inversions are local.
  bool isIdealPermutation(vector<int> &nums) {
    // Use a helper to check if every element is at most one position away
    // from its correct sorted index. If true for all, then every global
    // inversion is local.
    return allInversionsAreLocal(nums);
  }

private:
  // Helper function to check if abs(nums[i] - i) <= 1 for all i.
  // This ensures that elements are never displaced by more than one position,
  // so no "non-local" global inversions exist.
  bool allInversionsAreLocal(const vector<int> &nums) {
    int n = nums.size(); // Get the size of the permutation.

    // Iterate through each position in the array.
    for (int i = 0; i < n; ++i) {
      // If the difference between the current value's position and where it
      // would be in the sorted array (i.e., value == index in a sorted
      // permutation) is more than 1, there must be a long-range inversion.
      if (std::abs(nums[i] - i) > 1) {
        // This means nums[i] is out-of-place by more than one,
        // implying a non-local global inversion.
        return false;
      }
    }
    // All checks passed: all global inversions are local.
    return true;
  }
};
// @lc code=end
