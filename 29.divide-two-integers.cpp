/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <climits>
#include <cstdlib>
class Solution {
public:
  int divide(int dividend, int divisor) {
    // Handle overflow case: INT_MIN / -1 would overflow int range
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }
    // Special case: INT_MIN / 1 is still INT_MIN
    if (dividend == INT_MIN && divisor == 1) {
      return INT_MIN;
    }

    // Determine if the result should be negative
    // XOR: result is negative if only one of them is negative
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Convert both dividend and divisor to negative numbers
    // This avoids overflow when taking abs(INT_MIN)
    int dvd = dividend;
    int dvs = divisor;
    int result = 0;

    // Make both numbers negative (since abs(INT_MIN) overflows)
    if (dvd > 0)
      dvd = -dvd;
    if (dvs > 0)
      dvs = -dvs;

    // Subtract divisor from dividend using bit manipulation
    // Each time, try to subtract the largest shifted divisor possible
    while (dvd <= dvs) {
      int temp = dvs, multiple = 1;
      // Double temp and multiple as much as possible without overflow
      // and as long as temp << 1 is still >= dvd
      while (temp >= (INT_MIN >> 1) && dvd <= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
      }
      // Subtract the largest found chunk from dividend
      dvd -= temp;
      // Add the corresponding multiple to result
      result += multiple;
    }

    // Apply sign to result
    return negative ? -result : result;
  }
};
// @lc code=end
