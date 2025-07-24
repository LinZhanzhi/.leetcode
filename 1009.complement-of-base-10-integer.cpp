/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0)
      return 1;
    int mask = 0, temp = n;
    while (temp) {
      mask = (mask << 1) | 1;
      temp >>= 1;
    }
    // ~n is the bitwise NOT of n, which flips all the bits of n.
    // For example, if n = 5 (binary 101), ~n is ...11111010 (in two's
    // complement representation). To get the complement only for the bits that
    // n uses, we mask it with 'mask'.
    return (~n) & mask;
  }
};
// @lc code=end
