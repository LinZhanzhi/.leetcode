/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    long long rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      // Check for overflow before multiplying by 10 and adding pop
      // For positive numbers, if rev == INT_MAX / 10, then pop > 7 would cause
      // overflow (since INT_MAX is 2147483647, last digit is 7)
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        return 0;
      // For negative numbers, if rev == INT_MIN / 10, then pop < -8 would cause
      // underflow (since INT_MIN is -2147483648, last digit is -8)
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        return 0;
      rev = rev * 10 + pop;
    }
    return (int)rev;
  }
};
// @lc code=end
