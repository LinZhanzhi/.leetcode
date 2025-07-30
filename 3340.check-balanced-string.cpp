/*
 * @lc app=leetcode id=3340 lang=cpp
 *
 * [3340] Check Balanced String
 */

// @lc code=start
class Solution {
public:
  bool isBalanced(string num) {
    int evenSum = 0, oddSum = 0;
    for (int i = 0; i < num.size(); ++i) {
      int digit = num[i] - '0';
      if (i % 2 == 0) {
        evenSum += digit;
      } else {
        oddSum += digit;
      }
    }
    return evenSum == oddSum;
  }
};
// @lc code=end
