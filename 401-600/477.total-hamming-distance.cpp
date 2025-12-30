/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to compute the total Hamming distance between all pairs
 * of numbers in a given array. The Hamming distance between two numbers is the
 * number of bit positions where their binary representations differ. Instead of
 * comparing every pair directly (which is slow for large arrays), we need to
 * find a faster way to sum up all differing bits across all pairs.
 *
 * High-Level Summary:
 * ----
 * The efficient approach is to count, for each bit position (from 0 to 31), how
 * many numbers have a 1 and how many have a 0 at that position. For each bit,
 * the number of differing pairs is the product of the count of 1s and the count
 * of 0s at that bit position. Summing this product over all 32 bit positions
 * gives the total Hamming distance for all pairs. This approach avoids the
 * O(n^2) brute-force and runs in O(n * 32) time, which is efficient for the
 * input constraints. Space complexity is O(1) extra (besides the input array).
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace for convenience

// @lc code=start
class Solution {
public:
  // Main function to compute the total Hamming distance
  int totalHammingDistance(vector<int> &nums) {
    // There are at most 32 bits in the numbers (since 0 <= nums[i] <= 10^9)
    const int BIT_COUNT = 32;
    int n = nums.size();
    int total = 0; // This will store the final answer

    // For each bit position from 0 to 31
    for (int bit = 0; bit < BIT_COUNT; ++bit) {
      int countOnes = 0; // Count of numbers with a 1 at this bit position

      // Count how many numbers have a 1 at the current bit position
      for (int i = 0; i < n; ++i) {
        // (nums[i] >> bit) & 1 extracts the bit at position 'bit'
        if ((nums[i] >> bit) & 1) {
          ++countOnes;
        }
      }

      // The number of numbers with a 0 at this bit position
      int countZeros = n - countOnes;

      // For this bit, each pair of (1,0) contributes 1 to the Hamming distance
      // So, total pairs differing at this bit = countOnes * countZeros
      total += countOnes * countZeros;
    }

    // Return the total Hamming distance for all pairs
    return total;
  }
};
// @lc code=end
