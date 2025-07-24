/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    int a = 0, b = 0;
    int mulp = 1;
    while (n > 0) {
      int d = n % 10;
      n /= 10;
      if (d == 0) { // handling 10 => 1 & 9
        n--;
        a += 1 * mulp;
        b += 9 * mulp;
      } else if (d == 1 && n > 0) { // handling 11 => 2 & 9
        n--;
        a += 2 * mulp;
        b += 9 * mulp;
      } else {
        a += 1 * mulp;
        b += (d - 1) * mulp;
      }
      mulp *= 10;
    }
    return {a, b};
  }
};
// @lc code=end
