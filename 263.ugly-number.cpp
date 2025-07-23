/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
  bool isUgly(int n) {
    // Handle edge cases
    if (n <= 0)
      return false;
    if (n == 1)
      return true;

    // Keep dividing by 2, 3, and 5 until we can't
    while (n % 2 == 0)
      n /= 2;
    while (n % 3 == 0)
      n /= 3;
    while (n % 5 == 0)
      n /= 5;

    // If the result is 1, it's an ugly number
    return n == 1;
  }
};
// @lc code=end
