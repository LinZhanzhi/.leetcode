/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */

// Brief Digested Understanding:
// ----
// The problem is about escaping ghosts on a grid: you start from (0, 0)
// and need to reach the given target coordinate. Ghosts start at their own
// positions. All parties can move one square per turn (including staying
// still), and all move at the same time. You can only escape if you reach the
// target BEFORE any ghost can reach the target (arriving at the same time as a
// ghost does *not* count as escape). The crux: can you potentially "outrun" all
// the ghosts to the target?

// High-Level Summary:
// ----
// The key is that all agents can move one grid per turn, and all moves are
// simultaneous. Since neither you nor ghosts block each other and since all
// ghosts are equally mobile, the only consideration is "who can reach the
// target faster?" (i.e., in fewer or the same number of steps). The minimum
// steps from a point (x,y) to (a,b) on a grid where you can move in four
// directions is the Manhattan distance: |x-a| + |y-b|. You can escape if and
// only if *your* Manhattan distance from start (0,0) to target is strictly less
// than that of *all* the ghosts. If any ghost can reach the target in as few or
// fewer moves than you (<= your steps), you cannot escape. Thus, the approach:
//   - Compute your distance to the target.
//   - For each ghost, compute their distance. If any are less than or equal,
//   return false.
//   - If you beat all of them, return true.
// Time complexity: O(N), where N is the number of ghosts. Space complexity:
// O(1) extra not counting input.

#include <cstdlib> // For std::abs
#include <vector>  // For std::vector

using std::vector;

class Solution {
public:
  // Helper function to compute Manhattan distance between two points
  int manhattanDistance(const vector<int> &p1, const vector<int> &p2) {
    // Manhattan (taxicab) distance on a grid: |x1 - x2| + |y1 - y2|
    return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
  }

  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    // Compute your minimal steps from origin (0,0) to target.
    vector<int> origin = {0, 0}; // Your starting position
    int mySteps =
        manhattanDistance(origin, target); // Always your minimum steps

    // Check ghosts: for each, see if they can reach target as quickly as you.
    for (const auto &ghost : ghosts) {
      int ghostSteps = manhattanDistance(ghost, target);
      // If any ghost can reach in fewer or the same number of steps, escape is
      // impossible
      if (ghostSteps <= mySteps) {
        return false; // A ghost can intercept or tie you at the target
      }
    }

    // If all ghosts are farther (strictly), you can reach the target first
    return true;
  }
};
// @lc code=end
