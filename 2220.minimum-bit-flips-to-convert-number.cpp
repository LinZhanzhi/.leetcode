/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution {
public:
  int minBitFlips(int start, int goal) { return countSetBits(start ^ goal); }

private:
  // Counts the number of set bits (1s) in the binary representation of n.
  int countSetBits(int n) {
    int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
};
// @lc code=end
