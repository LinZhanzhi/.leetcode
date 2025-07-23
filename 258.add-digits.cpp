/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    // Mathematical solution: Digital Root
    // The digital root of a number is the value obtained by an iterative
    // process of summing digits until a single-digit number is achieved. For
    // any number n, the digital root is: 1 + (n-1) % 9 Special case: if n is 0,
    // the result is 0

    if (num == 0)
      return 0;
    return 1 + (num - 1) % 9;
  }

  // Alternative iterative solution (for understanding):
  /*
  int addDigits(int num) {
      while (num >= 10) {
          int sum = 0;
          while (num > 0) {
              sum += num % 10;
              num /= 10;
          }
          num = sum;
      }
      return num;
  }
  */
};
// @lc code=end
