/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given four integer arrays of equal length. We need to count how many
 * ways we can pick one element from each array so that their sum is exactly
 * zero. In other words, we want to count all quadruples (i, j, k, l) such that
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0. The challenge is to do this
 * efficiently, since a brute-force approach would be too slow for large arrays.
 */

/*
 * High-Level Summary:
 * ----
 * The efficient solution uses a hash map to store the sums of all pairs from
 * the first two arrays (nums1 and nums2) and their frequencies. Then, for each
 * possible sum of a pair from the last two arrays (nums3 and nums4), we check
 * if the negated sum exists in the hash map. If it does, we add the frequency
 * to our answer. This reduces the time complexity from O(n^4) to O(n^2).
 *
 * Algorithmic Assumptions:
 *   - All arrays are of equal length n (1 <= n <= 200).
 *   - The value range is large, so we use a hash map for efficient lookups.
 *
 * Time Complexity: O(n^2), since we process all pairs from two arrays twice.
 * Space Complexity: O(n^2), for storing all possible pair sums in the hash map.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to count the number of quadruples that sum to zero
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    // Step 1: Compute all possible sums of pairs from nums1 and nums2
    unordered_map<int, int> sumCount12 = computePairSums(nums1, nums2);

    // Step 2: For each possible sum of pairs from nums3 and nums4,
    // check if the negated sum exists in sumCount12
    int count = countComplementaryPairs(nums3, nums4, sumCount12);

    // Return the total count of quadruples
    return count;
  }

private:
  // Helper function to compute all possible sums of pairs from two arrays
  // and store their frequencies in a hash map
  unordered_map<int, int> computePairSums(const vector<int> &arr1,
                                          const vector<int> &arr2) {
    unordered_map<int, int> sumCount;
    // Iterate through every element in arr1
    for (int a : arr1) {
      // For each element in arr1, iterate through every element in arr2
      for (int b : arr2) {
        int sum = a + b; // Compute the sum of the pair
        sumCount[sum]++; // Increment the frequency of this sum
      }
    }
    // sumCount[sum] now tells us how many (i, j) pairs sum to 'sum'
    return sumCount;
  }

  // Helper function to count the number of complementary pairs from arr3 and
  // arr4 that, when added to a sum from sumCount12, result in zero
  int countComplementaryPairs(const vector<int> &arr3, const vector<int> &arr4,
                              const unordered_map<int, int> &sumCount12) {
    int count = 0;
    // Iterate through every element in arr3
    for (int c : arr3) {
      // For each element in arr3, iterate through every element in arr4
      for (int d : arr4) {
        int sum = c + d;   // Compute the sum of the pair
        int target = -sum; // We want the total sum to be zero, so look for -sum
        // If the complementary sum exists in sumCount12, add its frequency to
        // count
        if (sumCount12.count(target)) {
          count += sumCount12.at(target);
        }
      }
    }
    // count now holds the total number of quadruples that sum to zero
    return count;
  }
};
// @lc code=end
