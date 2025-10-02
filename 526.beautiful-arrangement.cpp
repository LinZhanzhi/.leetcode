/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a number n and need to count how many ways we can arrange the
 * numbers 1 to n so that for every position i (1-based), either the number at
 * that position divides i, or i divides the number at that position. This is a
 * permutation problem with a divisibility constraint at each position.
 *
 * High-Level Summary:
 * ----
 * The solution uses backtracking to try all possible arrangements of numbers 1
 * to n, but prunes the search whenever the divisibility condition is not met at
 * a given position. We use a bitmask to efficiently track which numbers have
 * already been used in the current arrangement. For each position, we try all
 * unused numbers and recursively proceed if the divisibility condition holds.
 * The time complexity is O(n!), but pruning makes it much faster in practice
 * for n <= 15. Space complexity is O(n) for the recursion stack and bitmask.
 */

// @lc code=start
#include <vector> // For std::vector

class Solution {
public:
  // Public function to count the number of beautiful arrangements for a given n
  int countArrangement(int n) {
    // Start the backtracking process from position 1, with no numbers used yet
    // (mask = 0)
    return backtrack(n, 1, 0);
  }

private:
  // Helper function for backtracking
  // n: total number of positions/numbers
  // pos: current position (1-based)
  // usedMask: bitmask representing which numbers have been used so far
  int backtrack(int n, int pos, int usedMask) {
    // Base case: if we've filled all positions, we've found a valid arrangement
    if (pos > n) {
      return 1;
    }
    int count = 0; // To count valid arrangements from this state

    // Try every number from 1 to n at the current position
    for (int num = 1; num <= n; ++num) {
      // Check if this number has already been used (bit is set in usedMask)
      if (!(usedMask & (1 << (num - 1)))) {
        // Check the divisibility condition for a beautiful arrangement
        if (num % pos == 0 || pos % num == 0) {
          // Mark this number as used by setting its bit in the mask
          int newMask = usedMask | (1 << (num - 1));
          // Recursively fill the next position
          count += backtrack(n, pos + 1, newMask);
        }
        // If the divisibility condition is not met, skip this number
      }
      // If the number is already used, skip it
    }
    // Return the total count of valid arrangements from this state
    return count;
  }
};
// @lc code=end
