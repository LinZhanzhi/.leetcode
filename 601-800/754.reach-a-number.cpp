/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */

/*
 * Brief Digested Understanding:
 * ----
 * The heart of this problem is finding the minimal number of moves needed to
 * reach a given target on the number line, where at each move the step size
 * increases by one and you can step left or right. The clever aspect is, you
 * don't have to decide the best direction for each move one by one; instead,
 * you want to sum up moves until the distance is enough, and then check whether
 * you can achieve the target by possibly swapping the sign (direction) of some
 * steps.
 *
 * Key constraint: The target is an integer (can be positive or negative, but
 * never zero), and you want the minimal moves to land exactly on it.
 *
 *
 * High-Level Summary:
 * ----
 * We approach the problem mathematically rather than by brute-force. The steps
 * taken after k moves sum up: 1 + 2 + ... + k = k*(k+1)/2. We want to find the
 * smallest k such that the sum is at least as large as the absolute value of
 * target *and* the difference between sum and target is even (since every sign
 * swap of a move changes the total position by an even value).
 *
 * Algorithm:
 *   1. Take the absolute value of target (the problem is symmetric).
 *   2. Increment k until the running sum reaches or surpasses target.
 *   3. If (sum - target) is even, it's possible to reach target by flipping
 * sign of some steps; otherwise, keep incrementing k.
 *
 *   Time Complexity: O(sqrt(target)), since the sum grows quadratically in k.
 *   Space Complexity: O(1), since only variables (no extra structures) are
 * used.
 */

// @lc code=start
#include <cstdlib> // For abs()

class Solution {
public:
  // Main function to find minimum moves to reach the target.
  int reachNumber(int target) {
    // Convert target to positive: reaching -target is symmetrical to target.
    int tgt = abs(target);

    // Helper function to calculate the minimum moves
    return minimumMovesToTarget(tgt);
  }

private:
  // Helper function to compute the moves needed for positive target.
  int minimumMovesToTarget(int tgt) {
    // Initialize the move counter and cumulative sum.
    int steps = 0;
    int sum = 0;

    // Keep taking steps until we pass or land on target.
    // We keep increasing steps and check if (sum - tgt) is even.
    while (true) {
      steps++;
      sum += steps;

      // Provide detailed explanation for each check:
      // If sum >= tgt and sum-tgt is even, it means we can
      // change the sign of some steps so that overall
      // we reach target exactly (since each flip alters position by 2k).
      if (sum >= tgt && (sum - tgt) % 2 == 0) {
        return steps;
      }
      // Else, loop continues: either sum is not enough, or adjustment not
      // possible yet.
    }
    // The loop always terminates because eventually (sum - tgt) will be even
    // for some steps.
  }
};
// @lc code=end
