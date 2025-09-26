/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We have n bulbs, all initially off. We perform n rounds of toggling: in the
 * i-th round, we toggle every i-th bulb. After all rounds, we want to know how
 * many bulbs remain on. The key insight is that a bulb ends up ON only if it is
 * toggled an odd number of times. This happens only for bulbs at positions that
 * are perfect squares (since only perfect squares have an odd number of
 * divisors).
 */

/*
 * High-Level Summary:
 * ----
 * The solution is based on the mathematical observation that only bulbs at
 * positions that are perfect squares will be toggled an odd number of times and
 * thus remain ON. For a given n, the number of perfect squares less than or
 * equal to n is simply the integer part of the square root of n (i.e.,
 * floor(sqrt(n))). Thus, we return floor(sqrt(n)).
 *
 * Time Complexity: O(1) — just a square root calculation.
 * Space Complexity: O(1) — no extra space used.
 */

// @lc code=start
#include <cmath> // Include cmath for sqrt function

class Solution {
public:
  int bulbSwitch(int n) {
    // The number of bulbs that remain ON is equal to the number of perfect
    // squares <= n. This is because only bulbs at positions with an odd number
    // of divisors (i.e., perfect squares) are toggled an odd number of times
    // and thus remain ON. We use sqrt(n) to count the number of perfect squares
    // up to n.
    return static_cast<int>(sqrt(n));
  }
};
// @lc code=end
