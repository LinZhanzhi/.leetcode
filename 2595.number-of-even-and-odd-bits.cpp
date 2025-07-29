/*
 * @lc app=leetcode id=2595 lang=cpp
 *
 * [2595] Number of Even and Odd Bits
 */

// @lc code=start
class Solution {
public:
  vector<int> evenOddBit(int n) {
    int even = 0, odd = 0;
    int idx = 0;
    while (n > 0) {
      if (n & 1) {
        if (idx % 2 == 0) {
          even++;
        } else {
          odd++;
        }
      }
      n >>= 1;
      idx++;
    }
    return {even, odd};
  }
};
// @lc code=end
