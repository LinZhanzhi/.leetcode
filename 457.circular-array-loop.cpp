/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a circular array of nonzero integers. Each value tells us how
 * many steps to move (forward if positive, backward if negative). We want to
 * determine if there exists a cycle (loop) in the array where:
 *   - The cycle has more than one element (no self-loops).
 *   - All steps in the cycle are in the same direction (all positive or all
 * negative).
 *   - The movement wraps around the array (circular).
 * The challenge is to efficiently detect such a cycle, ideally in O(n) time and
 * O(1) space.
 *
 * High-Level Summary:
 * ----
 * The solution uses a variant of Floyd's Tortoise and Hare (slow/fast pointer)
 * cycle detection algorithm. For each index, if it hasn't been visited, we try
 * to find a cycle starting from there, always moving in the same direction. If
 * a cycle is found (with length > 1), we return true. To avoid revisiting
 * paths, we mark visited elements by setting them to zero (since input is
 * guaranteed nonzero). This marking allows O(1) space. The main helper
 * functions are:
 *   - nextIndex: computes the next index in the circular array.
 *   - isValid: checks if the next move is in the same direction and not a
 * self-loop. The revised solution ensures that the direction is consistent
 * throughout the path and that cycles of length 1 (self-loops) are not counted.
 * It also marks all nodes in the current path as visited to avoid redundant
 * work. Time Complexity: O(n), since each element is visited at most twice.
 * Space Complexity: O(1), as we only use a few variables and modify the input
 * array in-place.
 */

#include <vector> // Include vector for std::vector
using std::vector;

// @lc code=start
class Solution {
public:
  // Helper function to compute the next index in the circular array
  int nextIndex(const vector<int> &nums, int curr) {
    int n = nums.size();
    // The modulo operation ensures we wrap around the array correctly.
    // Adding n before modulo handles negative values.
    return ((curr + nums[curr]) % n + n) % n;
  }

  // Helper function to check if the next move is valid:
  // - It must be in the same direction as the current move.
  // - It must not be a self-loop (i.e., not pointing to itself).
  // - It must match the original direction of the path.
  bool isValid(const vector<int> &nums, int curr, int next, bool isForward) {
    // Check direction: both current and next must have the same sign as
    // isForward
    if ((nums[next] > 0) != isForward)
      return false;
    // Check for self-loop (cycle of length 1 is not allowed)
    if (curr == next)
      return false;
    return true;
  }

  // Helper function to mark all nodes in the current path as visited (set to 0)
  // This prevents revisiting the same path in future iterations
  void markVisited(vector<int> &nums, int start, bool isForward) {
    int n = nums.size();
    int idx = start;
    while (true) {
      int next = nextIndex(nums, idx);
      // Stop if direction changes or already visited
      if ((nums[idx] > 0) != isForward || nums[idx] == 0)
        break;
      nums[idx] = 0; // Mark as visited
      if (next == idx)
        break; // Self-loop, stop marking
      idx = next;
    }
  }

  bool circularArrayLoop(vector<int> &nums) {
    int n = nums.size();

    // Iterate through each index as a possible starting point
    for (int i = 0; i < n; ++i) {
      // Skip if already visited (marked as 0)
      if (nums[i] == 0)
        continue;

      // Store the direction (positive or negative) for this path
      bool isForward = nums[i] > 0;

      // Use slow and fast pointers for cycle detection
      int slow = i, fast = i;

      // Loop to move slow by 1 step and fast by 2 steps
      while (true) {
        // Move slow pointer one step
        int nextSlow = nextIndex(nums, slow);
        // Check if slow pointer's move is valid (direction and not self-loop)
        if (!isValid(nums, slow, nextSlow, isForward))
          break;

        // Move fast pointer one step
        int nextFast = nextIndex(nums, fast);
        // Check if fast pointer's first move is valid
        if (!isValid(nums, fast, nextFast, isForward))
          break;
        // Move fast pointer a second step
        int nextFast2 = nextIndex(nums, nextFast);
        // Check if fast pointer's second move is valid
        if (!isValid(nums, nextFast, nextFast2, isForward))
          break;

        slow = nextSlow;
        fast = nextFast2;

        // If slow and fast meet, a cycle is found
        if (slow == fast) {
          // Additional check: cycle must be longer than 1 (no self-loop)
          // This is already ensured by isValid, but double-check for clarity
          if (slow == nextIndex(nums, slow))
            break;
          return true;
        }
      }

      // Mark all nodes in the current path as visited (set to 0)
      markVisited(nums, i, isForward);
    }
    // No valid cycle found
    return false;
  }
};
// @lc code=end
