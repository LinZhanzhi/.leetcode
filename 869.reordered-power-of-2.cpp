/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

/**
 * Brief Digested Understanding:
 * ----
 * The essence of this problem is: Given an integer n, can you rearrange its
 * digits (in any order, without leading zeros) to form a different integer
 * that is a power of 2? The digits in n can be shuffled, but you can’t add or
 * remove any digits, and the number cannot start with '0' unless it's zero
 * itself. The fundamental check is: Is there any permutation of n’s digits
 * that forms a power of 2?
 *
 * High-Level Summary:
 * ----
 * To efficiently solve this, we observe that if two numbers have the same
 * digit counts (regardless of order), and the number formed does not start
 * with zero, then their digit arrangements can permute into each other.
 * Instead of generating all possible permutations (which is slow), we
 * precompute the digit counts ("frequency signature") for every power of two
 * in n's possible range. We compare the digit-frequency of n with each power
 * of two in that range. If any match, n can be reordered to form a power of 2.
 * This approach is O(logN) (since there are at most 31 powers of 2 possible)
 * and uses constant space.
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  // Helper function to compute the "digit count signature" of a given integer.
  // This signature is a string representing the sorted digits of that integer.
  static std::string countDigits(int num) {
    // Create a string out of all digits of num.
    std::string s = std::to_string(num);
    // Sort the string in ascending order, so all permutations with the same
    // digits become identical.
    std::sort(s.begin(), s.end());
    // Return the signature string.
    return s;
  }

  // Main function to check if some permutation of n's digits can form a power
  // of 2.
  bool reorderedPowerOf2(int n) {
    // Compute the signature (sorted digits) of n.
    std::string nSignature = countDigits(n);

    // Iterate over all possible powers of 2 that fit within n's constraints.
    // For integers up to 10^9, 2^0 up to 2^29 are possible (since 2^30 is
    // 1,073,741,824 > 10^9).
    for (int i = 0; i < 31; ++i) {
      int pow2 = 1 << i; // Compute the current power of 2.
      // Compute the signature of this power of 2.
      std::string pow2Signature = countDigits(pow2);
      // If the digit counts (signatures) match, n can be rearranged to this
      // power of 2.
      if (nSignature == pow2Signature) {
        return true; // Found a valid arrangement.
      }
    }
    // If no matching signature is found among all powers of 2, return false.
    return false;
  }
};
// @lc code=end
