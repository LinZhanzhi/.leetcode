/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
  int findComplement(int num) {
    // To find the complement, create a mask with all bits set to 1 up to the
    // highest set bit in num, then XOR num with the mask.
    int mask = 0, temp = num;
    while (temp) {
      mask = (mask << 1) | 1;
      temp >>= 1;
    }
    return num ^ mask;
  }
};
// @lc code=end
