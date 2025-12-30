/*
 * @lc app=leetcode id=2160 lang=cpp
 *
 * [2160] Minimum Sum of Four Digit Number After Splitting Digits
 */

// @lc code=start
class Solution {
public:
  int minimumSum(int num) {
    // Extract digits
    vector<int> digits;
    for (int i = 0; i < 4; ++i) {
      digits.push_back(num % 10);
      num /= 10;
    }
    sort(digits.begin(), digits.end());
    // Form two numbers: smallest + third smallest, second smallest + largest
    int new1 = digits[0] * 10 + digits[2];
    int new2 = digits[1] * 10 + digits[3];
    return new1 + new2;
  }
};
// @lc code=end
