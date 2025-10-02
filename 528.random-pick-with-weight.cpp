/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to randomly pick an index from an array of weights such
 * that the chance of picking each index is proportional to its weight. For
 * example, if the weights are [1, 3], index 0 should be picked 25% of the time
 * and index 1 75% of the time. The challenge is to efficiently implement this
 * random selection so that each call to pickIndex() is fast, even for large
 * arrays.
 *
 * High-Level Summary:
 * ----
 * The solution uses a prefix sum array to map each index to a range of numbers
 * proportional to its weight. We generate a random number in the total weight
 * range and use binary search to find which index's range it falls into. This
 * ensures the correct probability for each index. The constructor precomputes
 * the prefix sums in O(N) time, and each pickIndex() call runs in O(log N) time
 * due to binary search. Space complexity is O(N) for storing the prefix sums.
 */

#include <numeric> // For std::partial_sum
#include <random>  // For random number generation
#include <vector>  // For std::vector

using std::vector;

// @lc code=start
class Solution {
private:
  vector<int> prefixSums; // Stores the prefix sums of weights
  int totalSum;           // Stores the total sum of all weights
  std::mt19937 rng;       // Mersenne Twister random number generator
  std::uniform_int_distribution<int> dist; // Distribution for random numbers

  // Helper function to build the prefix sum array from the weights
  void buildPrefixSums(const vector<int> &w) {
    prefixSums.resize(w.size());
    // Compute prefix sums: prefixSums[i] = w[0] + w[1] + ... + w[i]
    std::partial_sum(w.begin(), w.end(), prefixSums.begin());
    // The last element is the total sum of all weights
    totalSum = prefixSums.back();
  }

  // Helper function to set up the random number distribution
  void setupRandom() {
    // The random number should be in the range [1, totalSum]
    dist = std::uniform_int_distribution<int>(1, totalSum);
  }

  // Helper function to perform binary search on prefixSums
  // Returns the smallest index such that prefixSums[index] >= target
  int findIndex(int target) {
    int left = 0, right = prefixSums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // If prefixSums[mid] is less than target, search right half
      if (prefixSums[mid] < target) {
        left = mid + 1;
      } else {
        // Otherwise, search left half (including mid)
        right = mid;
      }
    }
    // left is the index where prefixSums[left] >= target
    return left;
  }

public:
  // Constructor: initializes the prefix sums and random number generator
  Solution(vector<int> &w)
      : rng(std::random_device{}()) // Seed the random number generator
  {
    buildPrefixSums(w); // Precompute prefix sums for efficient queries
    setupRandom();      // Set up the random number distribution
  }

  // Randomly picks an index with probability proportional to its weight
  int pickIndex() {
    // Generate a random integer in [1, totalSum]
    int target = dist(rng);
    // Use binary search to find the corresponding index
    return findIndex(target);
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
