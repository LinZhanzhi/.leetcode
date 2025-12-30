/*
 * @lc app=leetcode id=1952 lang=cpp
 *
 * [1952] Three Divisors
 */

// @lc code=start
class Solution {
public:
  bool isThree(int n) {
    // A number has exactly three positive divisors if and only if it is the
    // square of a prime.
    if (n < 4)
      return false;
    int root = sqrt(n);
    if (root * root != n)
      return false;
    // Check if root is prime
    for (int i = 2; i * i <= root; ++i) {
      if (root % i == 0)
        return false;
    }
    return true;
  }
};
// @lc code=end
