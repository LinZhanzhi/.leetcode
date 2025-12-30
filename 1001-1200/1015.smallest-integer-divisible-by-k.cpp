/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are looking for a number N consisting only of 1s (like 1, 11, 111...) such that N is divisible by K.
 * We need to return the length of the smallest such N.
 *
 * Key Observations:
 * 1. If K is even (divisible by 2) or divisible by 5, it's impossible.
 *    - Numbers ending in 1 are never divisible by 2 (they are odd).
 *    - Numbers ending in 1 are never divisible by 5 (must end in 0 or 5).
 * 2. We can generate the sequence of numbers:
 *    - N_1 = 1
 *    - N_2 = 11 = N_1 * 10 + 1
 *    - N_i = N_{i-1} * 10 + 1
 * 3. Since N can be very large (overflowing 64-bit integers), we only care about the remainder modulo K.
 *    - remainder_i = (remainder_{i-1} * 10 + 1) % K
 * 4. If we encounter a remainder of 0, we found our number.
 * 5. If we encounter a remainder we've seen before (entering a cycle) without seeing 0, then it's impossible.
 *    However, by Pigeonhole Principle, there are only K possible remainders (0 to K-1).
 *    If we iterate K times and don't find 0, we must have entered a cycle that doesn't include 0.
 *
 * High-Level Summary:
 * -------------------
 * 1. Check if K is divisible by 2 or 5. If so, return -1.
 * 2. Iterate starting with remainder = 0.
 * 3. In each step (representing length 1, 2, ...), update remainder: \
emainder = (remainder * 10 + 1) % K\.
 * 4. If remainder becomes 0, return the current length.
 * 5. If we iterate more than K times, it's impossible (though the initial check covers most cases, this is a safety bound).
 *
 * Time Complexity: O(K). The remainder cycle can have at most K states.
 * Space Complexity: O(1).
 */

// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // Optimization: Numbers ending in 1 are odd and not divisible by 5.
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int remainder = 0;
        for (int length = 1; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length;
            }
        }

        return -1;
    }
};
// @lc code=end
