/*
 * @lc app=leetcode id=1837 lang=cpp
 *
 * [1837] Sum of Digits in Base K
 */

// @lc code=start
class Solution {
public:
  int sumBase(int n, int k) {
    int sum = 0;
    while (n > 0) {
      sum += n % k;
      n /= k;
    }
    return sum;
  }
};
// @lc code=end
