/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    int count = 0;
    // Primes up to 20: 2,3,5,7,11,13,17,19
    // Use a bitmask for fast lookup: (1 << x) means x is prime if bit is set
    int prime_mask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 11) |
                     (1 << 13) | (1 << 17) | (1 << 19);
    for (int i = left; i <= right; ++i) {
      int set_bits = __builtin_popcount(i);
      if (prime_mask & (1 << set_bits)) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
