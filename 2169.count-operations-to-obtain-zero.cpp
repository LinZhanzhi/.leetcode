/*
 * @lc app=leetcode id=2169 lang=cpp
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
class Solution {
public:
  int countOperations(int num1, int num2) {
    int count = 0;
    while (num1 != 0 && num2 != 0) {
      if (num1 >= num2) {
        int times = num1 / num2;
        num1 -= times * num2;
        count += times;
      } else {
        int times = num2 / num1;
        num2 -= times * num1;
        count += times;
      }
    }
    return count;
  }
};
// @lc code=end
