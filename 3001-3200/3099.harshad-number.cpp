/*
 * @lc app=leetcode id=3099 lang=cpp
 *
 * [3099] Harshad Number
 */

// @lc code=start
class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0, n = x;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    if (x % sum == 0) {
      return sum;
    } else {
      return -1;
    }
  }
};
// @lc code=end
