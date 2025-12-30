/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// Brief Digested Understanding:
// ----
// This problem is about finding the longest sequence (chain) of pairs where
// each pair can "follow" the previous one, meaning the first value of the next
// pair is strictly greater than the second value of the previous pair. You can
// pick any subset of the pairs and arrange them in any order, as long as the
// chain rule is satisfied. The goal is to find the maximum possible length of
// such a chain.

// High-Level Summary:
// ----
// The optimal approach is to treat this as a variant of the "Longest Increasing
// Subsequence" (LIS) problem, but with intervals. A greedy algorithm works
// here: First, sort the pairs by their second value (right endpoint). Then,
// iterate through the sorted pairs, always picking the next pair whose left
// endpoint is greater than the right endpoint of the last chosen pair. This
// ensures the chain is as long as possible. The time complexity is O(n log n)
// due to sorting, and space complexity is O(1) (ignoring input storage), as we
// only need a few variables to track the chain.

// Include necessary headers for vector and sorting
#include <algorithm>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the longest chain of pairs
  int findLongestChain(vector<vector<int>> &pairs) {
    // Sort the pairs by their second value (right endpoint) in ascending order.
    // This allows us to always pick the next pair with the earliest possible
    // end, maximizing the chance to fit more pairs in the chain.
    std::sort(pairs.begin(), pairs.end(), compareBySecond);

    // Initialize the count of pairs in the chain.
    int chainLength = 0;
    // Initialize the end value of the last selected pair in the chain.
    // We use a very small value so that the first pair is always considered.
    int currentEnd = INT_MIN;

    // Iterate through each pair in the sorted list.
    for (const auto &pair : pairs) {
      int left = pair[0];  // The start of the current pair
      int right = pair[1]; // The end of the current pair

      // If the current pair can follow the last selected pair (i.e., its start
      // is greater than the end of the last pair in the chain), we can add it.
      if (left > currentEnd) {
        chainLength++;      // Increment the chain length
        currentEnd = right; // Update the end to the current pair's end
      }
      // If not, we skip this pair, as it cannot be chained after the last one.
    }

    // Return the maximum length of the chain found.
    return chainLength;
  }

private:
  // Helper function to compare two pairs by their second value (right
  // endpoint). This is used for sorting the pairs in the greedy algorithm.
  static bool compareBySecond(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
  }
};
// @lc code=end
