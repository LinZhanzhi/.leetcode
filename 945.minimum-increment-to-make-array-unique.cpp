/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

/**
 * Brief Digested Understanding:
 * ----
 * The problem asks how many "increment-by-one" moves are needed to ensure
 * that every element in a given array is unique; that is, no two elements share
 * the same value. We can only increment values (not decrement). Our goal is to
 * minimize the number of such moves. Think of each duplicate as needing to
 * “move up” to the next unused number to break ties.
 *
 * High-Level Summary:
 * ----
 * To minimize moves, sort the array so duplicates are adjacent. As we iterate
 * through the sorted values, for each element, if it’s not greater than the
 * previous, we need to increment it so it becomes exactly one larger than the
 * previous value. This way, every entry is unique, and we always do the minimal
 * increment needed. Sorting ensures we can process duplicates in order and
 * always “push up” only when required. The main algorithm is: sort + single
 * pass with counting. Sorting is O(n log n), and the single pass is O(n), so
 * overall time complexity is O(n log n), with O(1) extra space (ignoring sort’s
 * temp usage).
 */

#include <algorithm> // Needed for std::sort
#include <vector>    // Needed for std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the minimum increments needed to make array unique
  int minIncrementForUnique(vector<int> &nums) {
    // Edge case: if 0 or 1 elements, already unique, no increments needed
    if (nums.size() <= 1)
      return 0;

    // Step 1: Sort the array so that duplicates and close numbers are adjacent.
    std::sort(nums.begin(), nums.end());

    // This variable will accumulate the total number of needed increments
    int total_moves = 0;

    // The variable prev keeps track of the previous (processed) number
    // so that each number is at least prev+1 (unique and ascending order)
    int prev = nums[0]; // The first number is our starting point

    // Process from second element to the end
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] <= prev) {
        // If the current number is not greater than prev,
        // we must increase it to prev + 1 to ensure uniqueness
        int needed = prev + 1;

        // The difference tells how many increments are needed
        total_moves += (needed - nums[i]);

        // Update prev to the new unique value
        prev = needed;
      } else {
        // If already greater, no need to increment—just update prev
        prev = nums[i];
      }
    }

    // After processing, total_moves holds the minimal number of required
    // increments
    return total_moves;
  }
};
// @lc code=end
