/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We start with a list of numbers from 1 to n. In each round, we remove every
 * other number, alternating the direction (left-to-right, then right-to-left,
 * and so on) until only one number remains. The task is to find out which
 * number is left at the end, without actually simulating the whole list, since
 * n can be very large.
 *
 * High-Level Summary:
 * ----
 * Instead of simulating the elimination, we track the "head" (the first number
 * in the current list), the step size (distance between remaining numbers), and
 * the direction of elimination. In each round, we update the head and step
 * based on the direction and the number of remaining elements. This approach is
 * efficient and only uses a few variables, making it suitable for large n.
 *
 * Time Complexity: O(log n), since the number of elements halves each round.
 * Space Complexity: O(1), as we use only a constant number of variables.
 */

// @lc code=start
class Solution {
public:
  int lastRemaining(int n) {
    // 'head' keeps track of the first number in the current list after each
    // elimination round.
    int head = 1;
    // 'step' is the distance between consecutive remaining numbers after each
    // round.
    int step = 1;
    // 'left' indicates the direction: true for left-to-right, false for
    // right-to-left.
    bool left = true;
    // 'remaining' is the number of elements left in the current round.
    int remaining = n;

    // Continue until only one number remains.
    while (remaining > 1) {
      // If we are moving left-to-right, or if the number of remaining elements
      // is odd when moving right-to-left, the head will always move forward by
      // 'step'. This is because, in these cases, the first element is always
      // eliminated.
      if (left || remaining % 2 == 1) {
        head += step;
      }
      // After each round, half the numbers are eliminated, so we halve
      // 'remaining'.
      remaining /= 2;
      // The step size doubles, since every other number is removed.
      step *= 2;
      // Alternate the direction for the next round.
      left = !left;
    }
    // When only one number remains, 'head' is the answer.
    return head;
  }
};
// @lc code=end
