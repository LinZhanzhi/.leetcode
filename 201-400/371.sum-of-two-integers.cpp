/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to add two integers, `a` and `b`, but without using the standard
 * addition (+) or subtraction (-) operators. Instead, we must use bitwise
 * operations to simulate the process of addition, just like how addition is
 * performed at the hardware level using logic gates.
 *
 * The key idea is to use XOR (^) to add numbers without carrying, and AND (&)
 * followed by a left shift (<<) to compute the carry. We repeat this process
 * until there is no carry left.
 */

/*
 * High-Level Summary:
 * ----
 * The solution repeatedly applies two bitwise operations:
 *   1. XOR (^) to add the numbers without considering the carry.
 *   2. AND (&) and left shift (<<) to calculate the carry.
 * The carry is then added to the result in the next iteration. This process
 * continues until there is no carry left, at which point the result is the sum.
 *
 * Assumptions:
 *   - The input integers are within the range [-1000, 1000], so 32-bit signed
 *     integer operations are sufficient.
 *   - The solution works for both positive and negative numbers due to the way
 *     two's complement representation works in C++.
 *
 * Time Complexity:
 *   - O(1) in practice, since the number of bits is fixed (32 for int).
 *   - Each iteration processes one bit position, and there are at most 32 bits.
 *
 * Space Complexity:
 *   - O(1), as only a constant amount of extra space is used.
 */

// @lc code=start
class Solution {
public:
  int getSum(int a, int b) {
    // Loop until there is no carry left
    while (b != 0) {
      // Calculate the carry bits (where both a and b have 1s)
      int carry = (unsigned int)(a & b) << 1;
      // XOR adds the numbers without carrying
      a = a ^ b;
      // The carry is added in the next iteration
      b = carry;
      // The loop continues until carry is zero, meaning no more bits to add
    }
    // When carry is zero, a contains the final sum
    return a;
  }
};
/*
 * Example: How the Bitwise Addition Works (Input: a = 2, b = 3)
 * ----
 * Let's walk through the process step by step for a = 2 and b = 3:
 *
 * Initial values:
 *   a = 2 (binary:  0010)
 *   b = 3 (binary:  0011)
 *
 * 1st iteration:
 *   - carry = (a & b) << 1
 *           = (0010 & 0011) << 1
 *           = (0010) << 1
 *           = 0100 (decimal 4)
 *   - a = a ^ b
 *       = 0010 ^ 0011
 *       = 0001 (decimal 1)
 *   - b = carry = 0100 (decimal 4)
 *
 * 2nd iteration:
 *   a = 1 (0001), b = 4 (0100)
 *   - carry = (a & b) << 1
 *           = (0001 & 0100) << 1
 *           = (0000) << 1
 *           = 0000 (decimal 0)
 *   - a = a ^ b
 *       = 0001 ^ 0100
 *       = 0101 (decimal 5)
 *   - b = carry = 0000 (decimal 0)
 *
 * Now b is 0, so the loop ends. The result is a = 5, which is the correct sum
 * of 2 and 3.
 *
 * This example demonstrates how the algorithm uses bitwise operations to add
 * two numbers without using the '+' operator.
 */
// @lc code=end
