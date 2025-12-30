/*
 * @lc app=leetcode id=2520 lang=cpp
 *
 * [2520] Count the Digits That Divide a Number
 */

// @lc code=start
class Solution {
public:
  int countDigits(int num) {
    int count = 0;
    int n = num;
    while (n > 0) {
      int digit = n % 10;
      if (num % digit == 0) {
        count++;
      }
      n /= 10;
    }
    return count;
  }
};
// @lc code=end
