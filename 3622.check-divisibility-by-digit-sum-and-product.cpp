/*
 * @lc app=leetcode id=3622 lang=cpp
 *
 * [3622] Check Divisibility by Digit Sum and Product
 */

// @lc code=start
class Solution {
public:
  bool checkDivisibility(int n) {
    int sum = 0, prod = 1, temp = n;
    while (temp > 0) {
      int d = temp % 10;
      sum += d;
      prod *= d;
      temp /= 10;
    }
    int total = sum + prod;
    if (total == 0)
      return false; // avoid division by zero, though not possible for n >= 1
    return n % total == 0;
  }
};
// @lc code=end
