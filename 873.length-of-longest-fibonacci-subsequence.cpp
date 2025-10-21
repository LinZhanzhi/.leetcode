/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start

/*
 * Brief Digested Understanding:
 * ----
 * Given a strictly increasing sequence of positive integers, we want to find
 * the longest subsequence (retaining order, can skip elements) where each term
 * (after the first two) is the sum of the two preceding elements—like the
 * Fibonacci sequence. The goal is to return the length of the longest such
 * subsequence found, where its length is at least 3, or 0 if none exists.
 *
 * The key challenge is efficiently finding such subsequences, since randomly
 * checking all combinations would be far too slow for sequences up to length
 * 1,000.
 *
 * High-Level Summary:
 * ----
 * We'll use dynamic programming (DP) with hashing for efficient lookups. For
 * any pair of indices (i,j) in the array, representing a potential end of a
 * Fibonacci-like subsequence (with arr[i] and arr[j] as the last two entries),
 * we check if arr[j] - arr[i] exists somewhere earlier in the array. If it
 * does, and its index is less than i, we can "extend" a smaller subsequence
 * ending in (k,i) to now end in (i,j). We'll store DP lengths in a 2D table and
 * efficiently look up previous elements using a hashmap mapping value to index.
 * We seek the maximal DP value found, all at least size 3, and return it (or
 * 0).
 *
 * Main tools: dynamic programming (DP table), hash map for O(1) value-to-index
 * lookup. Time complexity is O(N^2) and space is O(N^2), both are acceptable
 * for N ≤ 1000.
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using std::max;
using std::unordered_map;
using std::vector;

class Solution {
public:
  int lenLongestFibSubseq(vector<int> &arr) {
    // Helper: map each value to its index for O(1) lookups.
    unordered_map<int, int> val_to_index = buildValueIndexMap(arr);

    int n = arr.size();
    // dp[i][j] = length of the longest Fib-like subsequence ending with arr[i],
    // arr[j]
    vector<vector<int>> dp(n,
                           vector<int>(n, 2)); // Start with len=2: minimal pair

    int maxLen = 0; // To keep track of the maximal length found

    // Iterate over all pairs (i, j) with i < j to build potential subsequences
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < j; ++i) {
        // To be Fib-like: there must exist k < i so that arr[k] + arr[i] ==
        // arr[j]
        int prev = arr[j] - arr[i];
        // arr[k] == prev, and k < i, and arr[k] exists
        if (prev < arr[i] && val_to_index.count(prev)) {
          int k = val_to_index[prev];
          // If valid, extend the sequence
          dp[i][j] = dp[k][i] + 1;
          maxLen = max(maxLen, dp[i][j]);
        }
        // Otherwise, dp[i][j] remains 2 (cannot extend: trivial pair)
      }
    }

    // At least length 3 is required
    return maxLen >= 3 ? maxLen : 0;
  }

private:
  // Helper function: Builds a hash map to map each array value to its index.
  // This allows O(1) lookup for "what index contains a value v?"
  unordered_map<int, int> buildValueIndexMap(const vector<int> &arr) {
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); ++i) {
      m[arr[i]] = i;
    }
    return m;
  }
};
// @lc code=end
