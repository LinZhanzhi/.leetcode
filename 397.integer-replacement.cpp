/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is: Given a positive integer n, how many steps does it take to
 * reduce n to 1, using these rules:
 * - If n is even, divide it by 2.
 * - If n is odd, you can either add 1 or subtract 1.
 * The goal is to find the minimum number of such operations needed to reach 1.
 *
 * The main challenge is making the optimal choice at each step, especially when
 * n is odd, to minimize the total number of steps.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses a greedy approach with iteration to minimize the number of
 * steps.
 * - If n is even, dividing by 2 is always optimal.
 * - If n is odd, we must choose between n+1 and n-1. The best choice is usually
 * the one that leads to more trailing zeros in binary (i.e., makes the next
 * number more divisible by 2).
 * - Special care is needed for the case when n is INT_MAX (2^31-1), to avoid
 * integer overflow. This is handled by using a variable of type long long to
 * store n, so that n+1 does not overflow.
 *
 * Time Complexity: O(log n), since each operation at least halves n.
 * Space Complexity: O(1), since we use only a constant amount of extra space.
 */

// @lc code=start
class Solution {
public:
  int integerReplacement(int n) {
    // Use long long to avoid overflow when n == INT_MAX and we do n+1
    // This is necessary because INT_MAX + 1 would overflow a 32-bit int,
    // but is safely handled by a 64-bit long long.
    long long num = n;
    int steps = 0; // Counter for the number of operations

    // Loop until num becomes 1
    while (num != 1) {
      if ((num & 1) == 0) {
        // If num is even, divide by 2 (right shift by 1)
        num >>= 1;
      } else {
        // If num is odd, decide between num+1 and num-1
        // Special case: if num == 3, it's better to go to 2 (num-1)
        if (num == 3) {
          num -= 1;
        } else if ((num & 2) == 0) {
          // If the second least significant bit is 0, prefer num-1
          // This makes the result more divisible by 2 in the next step
          num -= 1;
        } else {
          // Otherwise, prefer num+1
          num += 1;
        }
      }
      steps++; // Increment the operation count
    }
    return steps;
  }
};
// @lc code=end
