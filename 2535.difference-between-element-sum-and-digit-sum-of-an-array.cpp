/*
 * @lc app=leetcode id=2535 lang=cpp
 *
 * [2535] Difference Between Element Sum and Digit Sum of an Array
 */

// @lc code=start
class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    int elementSum = 0, digitSum = 0;
    for (int num : nums) {
      elementSum += num;
      int n = num;
      while (n > 0) {
        digitSum += n % 10;
        n /= 10;
      }
    }
    return abs(elementSum - digitSum);
  }
};
// @lc code=end
