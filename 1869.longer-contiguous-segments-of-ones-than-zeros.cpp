/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */

// @lc code=start
class Solution {
public:
  bool checkZeroOnes(string s) {
    int max1 = 0, max0 = 0;
    int cur1 = 0, cur0 = 0;
    for (char c : s) {
      if (c == '1') {
        cur1++;
        cur0 = 0;
      } else {
        cur0++;
        cur1 = 0;
      }
      if (cur1 > max1)
        max1 = cur1;
      if (cur0 > max0)
        max0 = cur0;
    }
    return max1 > max0;
  }
};
// @lc code=end
