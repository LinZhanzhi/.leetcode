/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
  int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
      if (num % 2 == 0) {
        num /= 2;
      } else {
        num -= 1;
      }
      steps++;
    }
    return steps;
  }
};
// @lc code=end
