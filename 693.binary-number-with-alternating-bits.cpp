/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
  bool hasAlternatingBits(int n) {
    unsigned int x =
        static_cast<unsigned int>(n) ^ (static_cast<unsigned int>(n) >> 1);
    return (x & (x + 1)) == 0;
  }
};
// @lc code=end
