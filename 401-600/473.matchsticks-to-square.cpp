/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a set of matchsticks, each with a certain length, and we want to
 * use all of them (without breaking any) to form a square. This means we need
 * to partition the matchsticks into four groups, each group summing to the same
 * length (the side of the square). Each matchstick must be used exactly once.
 *
 * High-Level Summary:
 * ----
 * The solution checks if the total length of all matchsticks is divisible by 4
 * (since a square has four equal sides). If not, it's impossible. If it is, we
 * try to assign each matchstick to one of the four sides using a recursive
 * backtracking approach, always ensuring that no side exceeds the target
 * length. We sort the matchsticks in descending order to optimize the search
 * (placing longer sticks first helps prune impossible paths early). The
 * algorithm tries all possible assignments and returns true if a valid square
 * can be formed.
 *
 * Time Complexity: O(4^N), where N is the number of matchsticks (since each
 * stick can go to any of 4 sides), but pruning and sorting make it much faster
 * in practice. Space Complexity: O(N) for recursion stack and side arrays.
 */

#include <algorithm> // For std::sort
#include <vector>    // For std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to determine if matchsticks can form a square
  bool makesquare(vector<int> &matchsticks) {
    // Calculate the total length of all matchsticks
    int total = 0;
    for (int len : matchsticks)
      total += len;

    // If total length is not divisible by 4, we cannot form a square
    if (total % 4 != 0)
      return false;

    int side = total / 4; // Each side of the square must have this length

    // Sort matchsticks in descending order to optimize backtracking
    std::sort(matchsticks.rbegin(), matchsticks.rend());

    // If the longest matchstick is longer than the side, it's impossible
    if (matchsticks[0] > side)
      return false;

    // Array to keep track of the current length of each side
    vector<int> sides(4, 0);

    // Start recursive backtracking from the first matchstick
    return backtrack(matchsticks, 0, sides, side);
  }

private:
  // Helper function for recursive backtracking
  // idx: current matchstick index
  // sides: current lengths of the 4 sides
  // target: required length for each side
  bool backtrack(const vector<int> &matchsticks, int idx, vector<int> &sides,
                 int target) {
    // Base case: if all matchsticks have been placed
    if (idx == matchsticks.size()) {
      // Check if all sides are exactly equal to the target length
      return sides[0] == target && sides[1] == target && sides[2] == target &&
             sides[3] == target;
    }

    // Try to place the current matchstick on each side
    for (int i = 0; i < 4; ++i) {
      // If placing the matchstick does not exceed the target length
      if (sides[i] + matchsticks[idx] <= target) {
        sides[i] += matchsticks[idx]; // Place the matchstick

        // Recursively try to place the next matchstick
        if (backtrack(matchsticks, idx + 1, sides, target)) {
          return true; // Found a valid arrangement
        }

        sides[i] -= matchsticks[idx]; // Backtrack: remove the matchstick
      }

      // Optimization: if this side is still 0 after trying, no need to try
      // other empty sides
      if (sides[i] == 0)
        break;
    }

    // No valid arrangement found for this configuration
    return false;
  }
};
// @lc code=end
