/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * High-Level Summary:
 * -------------------
 * Problem: Given two integers 'left' and 'right', compute the bitwise AND of
 * all numbers in the inclusive range [left, right].
 *
 * Approach:
 * - The key insight is that as you perform bitwise AND across a range of
 * numbers, any bit position that changes (i.e., flips from 0 to 1 or 1 to 0)
 * within the range will result in a 0 in the final answer at that position.
 * - Therefore, the result is the common bitwise prefix (the leftmost bits that
 * are the same) of 'left' and 'right', with all differing bits (to the right)
 * set to 0.
 * - To find this common prefix, we repeatedly right-shift both 'left' and
 * 'right' until they become equal, counting how many shifts we perform.
 * - Finally, we left-shift the common prefix back by the number of shifts to
 * restore its original position, filling the differing bits with zeros.
 *
 * Assumptions:
 * - 0 <= left <= right <= 2^31 - 1 (as per LeetCode constraints)
 * - The function handles all edge cases, including when left == right (the AND
 * is the number itself), and when the range is large (all bits may be zeroed).
 *
 * Time Complexity: O(1) in practice, since integers are at most 32 bits
 * (constant number of shifts). Space Complexity: O(1), as only a few integer
 * variables are used.
 */

// @lc code=start
class Solution {
public:
  // This function computes the bitwise AND of all numbers in the range [left,
  // right].
  int rangeBitwiseAnd(int left, int right) {
    // Variable 'shift' will count how many times we need to right-shift both
    // 'left' and 'right' to make them equal. This is equivalent to finding the
    // length of the common prefix in their binary representations.
    int shift = 0;

    // The loop continues as long as 'left' and 'right' are not equal.
    // At each iteration, we right-shift both numbers by 1 (i.e., divide by 2
    // and discard the least significant bit). This effectively removes the
    // rightmost bit, moving us closer to the common prefix. Why do we do this?
    // Because any bit position where 'left' and 'right' differ means that, in
    // the range, all possible combinations of 0 and 1 will occur at that
    // position, so the AND will be 0 there.
    while (left < right) {
      // Right-shift both 'left' and 'right' by 1 to remove the least
      // significant bit.
      left >>= 1;
      right >>= 1;
      // Increment 'shift' to keep track of how many bits we've removed.
      ++shift;
      // Example: If left=26 (11010) and right=30 (11110), after one shift:
      // left=13 (1101), right=15 (1111) Continue until left == right, which
      // means we've found the common prefix.
    }

    // At this point, 'left' and 'right' are equal and represent the common
    // prefix of all numbers in the range. To reconstruct the answer, we
    // left-shift 'left' back by 'shift' positions. This fills the rightmost
    // 'shift' bits with zeros, which is correct because those bits would have
    // been zeroed out by the AND operation over the range.
    return left << shift;
    // Example: If the common prefix is 110 (6) and shift=2, the answer is 11000
    // (24). This is the bitwise AND of all numbers in the original range.
  }
};
// @lc code=end
