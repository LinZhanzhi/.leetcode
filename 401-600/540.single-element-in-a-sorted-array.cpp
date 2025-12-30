/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a sorted array where every element appears exactly twice except
 * for one element, which appears only once. Our task is to find and return this
 * single element. The array is sorted, which means the unique element disrupts
 * the otherwise perfect pairing of elements.
 *
 * High-Level Summary:
 * ----
 * To achieve O(log n) time and O(1) space, we use a binary search approach. The
 * key insight is that pairs of equal elements appear at even-odd indices before
 * the single element, and this pattern breaks at the single element. By
 * checking the mid index and its neighbor, we can determine which half of the
 * array contains the single element and adjust our search range accordingly.
 * This process continues until we find the unique element.
 *
 * Time Complexity: O(log n) due to binary search.
 * Space Complexity: O(1) since we use only a few variables.
 */

#include <vector>  // Include vector for std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // Main function to find the single non-duplicate element in a sorted array
  int singleNonDuplicate(vector<int> &nums) {
    // Use binary search to efficiently find the single element
    int left = 0;
    int right = nums.size() - 1;

    // Continue searching while the search space is valid
    while (left < right) {
      // Calculate the middle index
      int mid = left + (right - left) / 2;

      // Ensure mid is even for easier pair comparison
      if (mid % 2 == 1) {
        mid--; // Move mid to the left if it's odd
      }

      // Check if the pair starting at mid is valid
      if (nums[mid] == nums[mid + 1]) {
        // The single element must be after this pair
        // Move left boundary to mid + 2 (skip this pair)
        left = mid + 2;
      } else {
        // The single element is at mid or before
        // Move right boundary to mid
        right = mid;
      }
    }

    // When left == right, we've found the single element
    return nums[left];
  }
};
// @lc code=end
