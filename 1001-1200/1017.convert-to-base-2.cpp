/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to convert a positive integer n into its base -2 representation.
 * In a standard base conversion (like base 2 or base 10), we repeatedly take the remainder
 * modulo the base to get the current digit, and then divide the number by the base.
 *
 * For a negative base b = -2, the standard division algorithm n = q * b + r still applies,
 * but we must ensure the remainder r is non-negative (specifically 0 or 1 for base -2).
 * In C++, the % operator can return negative remainders for negative divisors.
 * If r is negative (e.g., -1), we can adjust the quotient and remainder:
 *   n = q * (-2) + (-1)
 *   n = (q + 1) * (-2) + (-1 + 2)
 *   n = (q + 1) * (-2) + 1
 * So, if remainder is -1, we add 1 to the quotient and set remainder to 1.
 *
 * Mathematical Definition:
 * ------------------------
 * A number N represented in base b (where b is an integer, positive or negative)
 * is a sequence of digits d_k...d_1 d_0 such that:
 *   N = sum(d_i * b^i) for i from 0 to k
 * where each digit d_i satisfies 0 <= d_i < |b|.
 *
 * For base b = -2, the digits must be 0 or 1.
 * The conversion process finds these digits by repeatedly applying the division algorithm:
 *   N = quotient * b + remainder
 * subject to the constraint 0 <= remainder < |b|.
 *
 * High-Level Summary:
 * -------------------
 * 1. Handle the edge case n = 0 immediately returning "0".
 * 2. Loop while n != 0:
 *    - Calculate remainder r = n % -2.
 *    - Calculate quotient n = n / -2.
 *    - If r < 0:
 *      - r += 2 (make remainder positive)
 *      - n += 1 (adjust quotient to compensate)
 *    - Append r to the result string.
 * 3. Reverse the result string since we generated digits from least significant to most significant.
 *
 * Time Complexity: O(log n). The number of digits is logarithmic with respect to n.
 * Space Complexity: O(log n) to store the result string.
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";

        string res = "";
        while (n != 0) {
            int remainder = n % -2;
            n /= -2;

            // In C++, remainder can be negative (e.g., -1).
            // We need remainder to be 0 or 1.
            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }

            res += to_string(remainder);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
