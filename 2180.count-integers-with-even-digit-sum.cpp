/*
 * @lc app=leetcode id=2180 lang=cpp
 *
 * [2180] Count Integers With Even Digit Sum
 */

// @lc code=start
class Solution {
public:
  int countEven(int num) {
    auto digitSum = [](int x) {
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };
    int count = 0;
    for (int i = 1; i <= num; ++i) {
      if (digitSum(i) % 2 == 0) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
