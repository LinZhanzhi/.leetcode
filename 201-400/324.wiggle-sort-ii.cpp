/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to rearrange the input array so that it alternates between
 * "less than" and "greater than" relationships: nums[0] < nums[1] > nums[2] <
 * nums[3]... This is called a "wiggle" pattern. The challenge is to do this
 * efficiently, ideally in O(n) time and O(1) extra space, and to handle
 * duplicate numbers correctly.
 *
 * High-Level Summary:
 * ----
 * The solution uses a three-step approach:
 *   1. Find the median of the array using the nth_element algorithm (O(n)
 * time).
 *   2. Use a virtual indexing trick to map indices so that we can rearrange the
 * array in-place.
 *   3. Apply a three-way partition (Dutch National Flag) to place numbers
 * greater than the median at odd indices, less than the median at even indices,
 * and medians in the middle. This ensures the wiggle property is satisfied. The
 * virtual index mapping is key to achieving the in-place rearrangement.
 *
 * Time Complexity: O(n) (due to nth_element and single pass partition)
 * Space Complexity: O(1) (in-place, ignoring recursion stack for nth_element)
 */

#include <algorithm> // Include algorithm for std::nth_element and std::swap
#include <vector>    // Include vector for std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    // Get the size of the input array
    int n = nums.size();

    // Step 1: Find the median of the array.
    // We use nth_element to partially sort the array so that the element at
    // position mid is the median (or one of the medians if n is even).
    int mid = (n - 1) / 2;
    auto midPtr = nums.begin() + mid;
    std::nth_element(nums.begin(), midPtr, nums.end());
    int median = nums[mid];

    // Step 2: Virtual Index Mapping
    // The mapping ensures that the larger numbers go to the odd indices and
    // smaller numbers to even. The formula maps the original index i to a new
    // index:
    //   mappedIndex = (1 + 2*i) % (n | 1)
    // This cycles through odd indices first, then even indices.
    auto virtualIndex = [n](int i) -> int { return (1 + 2 * i) % (n | 1); };

    // Step 3: Three-way partition (Dutch National Flag)
    // We use three pointers: left, i, and right.
    // - left: boundary for elements greater than median
    // - right: boundary for elements less than median
    // - i: current element being considered
    int left = 0, i = 0, right = n - 1;
    while (i <= right) {
      int vi = virtualIndex(i);
      if (nums[vi] > median) {
        // If current element is greater than median, put it in the left (odd
        // index) side
        std::swap(nums[virtualIndex(left)], nums[vi]);
        ++left;
        ++i;
      } else if (nums[vi] < median) {
        // If current element is less than median, put it in the right (even
        // index) side
        std::swap(nums[vi], nums[virtualIndex(right)]);
        --right;
      } else {
        // If current element is equal to median, just move on
        ++i;
      }
    }
    // After this process, the array is rearranged in-place to satisfy the
    // wiggle property.
  }
};
// @lc code=end
