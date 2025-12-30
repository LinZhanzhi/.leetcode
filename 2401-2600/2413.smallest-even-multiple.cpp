/*
 * @lc app=leetcode id=2413 lang=cpp
 *
 * [2413] Smallest Even Multiple
 */

// @lc code=start
class Solution {
public:
  int smallestEvenMultiple(int n) {
    // If n is even, n is the smallest even multiple. If n is odd, 2*n is the
    // answer.
    return (n % 2 == 0) ? n : 2 * n;
  }
};
// @lc code=end
