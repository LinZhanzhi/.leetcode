/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given an array where every number appears exactly twice except for two
 * numbers, which each appear only once. Our task is to find these two unique
 * numbers. The challenge is to do this in linear time (O(n)) and with constant
 * extra space (O(1)), so we cannot use hash maps or extra arrays proportional
 * to the input size.
 *
 * High-Level Summary:
 * ----
 * The solution leverages the properties of the XOR (^) operation:
 *   - XOR of a number with itself is 0.
 *   - XOR of a number with 0 is the number itself.
 *   - XOR is commutative and associative.
 * By XORing all numbers, we get the XOR of the two unique numbers (since all
 * duplicates cancel out). We then find a bit where these two numbers differ (a
 * set bit in the XOR result). Using this bit, we partition the numbers into two
 * groups: one group with this bit set, one without. Each group contains one
 * unique number and the rest are pairs, so XORing within each group gives the
 * unique numbers. Time Complexity: O(n), Space Complexity: O(1).
 *
 * Important Implementation Note:
 * ----
 * To safely isolate the rightmost set bit in xor_result (even if xor_result is
 * INT_MIN, e.g., -2147483648), we must cast xor_result to an unsigned type
 * before negation. This avoids undefined behavior due to negating INT_MIN in
 * two's complement representation.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    // Step 1: XOR all numbers to get xor_result = a ^ b,
    // where a and b are the two unique numbers.
    int xor_result = 0;
    for (int num : nums) {
      xor_result ^= num; // XOR accumulates all numbers; duplicates cancel out
    }
    // At this point, xor_result = a ^ b, and a != b

    // Step 2: Find any set bit (1) in xor_result.
    // This bit is different between a and b.
    // We use the rightmost set bit for simplicity.
    // To avoid undefined behavior when xor_result == INT_MIN,
    // cast to unsigned before negation.
    int diff_bit = xor_result & static_cast<unsigned int>(
                                    -static_cast<unsigned int>(xor_result));
    // Explanation:
    // -static_cast<unsigned int>(xor_result) computes the two's complement
    // safely, even if xor_result is INT_MIN. The cast ensures no overflow/UB.
    // The result isolates the lowest set bit in xor_result.

    // Step 3: Partition numbers into two groups based on diff_bit,
    // and XOR within each group to find the unique numbers.
    int num1 = 0, num2 = 0;
    for (int num : nums) {
      if (num & diff_bit) {
        // The bit is set in this number; XOR into first group
        num1 ^= num;
      } else {
        // The bit is not set; XOR into second group
        num2 ^= num;
      }
    }
    // num1 and num2 are the two unique numbers

    // Return the two unique numbers as a vector.
    return {num1, num2};
  }
};
// @lc code=end
