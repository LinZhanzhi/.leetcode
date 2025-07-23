/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
  int hammingDistance(int x, int y) {
    int xor_val = x ^ y;
    int count = 0;
    while (xor_val) {
      count += xor_val & 1;
      xor_val >>= 1;
    }
    return count;
  }
};
// @lc code=end
