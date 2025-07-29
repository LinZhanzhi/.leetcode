/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution {
public:
  int differenceOfSums(int n, int m) {
    int total = n * (n + 1) / 2;
    int k = n / m;
    int divisible = m * k * (k + 1);
    return total - divisible;
  }
};
// @lc code=end
