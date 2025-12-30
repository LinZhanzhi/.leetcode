/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
  double myPow(double x, int n) {
    // Fast power (exponentiation by squaring), handle negative n carefully
    if (n == 0)
      return 1.0;
    long long N = n;
    if (N < 0) {
      x = 1.0 / x;
      N = -N;
    }
    double result = 1.0;
    while (N > 0) {
      if (N % 2 == 1) {
        result *= x;
      }
      x *= x;
      N /= 2;
    }
    return result;
  }
};
// @lc code=end
