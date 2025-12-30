/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start

#include <algorithm>     // For std::sort
#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about counting all possible full binary trees (not just one)
 * where every node's value comes from a given array. Each non-leaf node must
 * have a value that is the product of its left and right children’s values.
 * The array has distinct positive integers greater than 1, and you can reuse
 * any number in any number of different trees, as long as the "product" rule
 * is followed at every non-leaf node.
 *
 * In essence: For each number in the array, count all the ways it can be the
 * root of a binary tree—by considering every pair of numbers whose product
 * equals that number (and the subtree counts for those factors). Combine count
 * of trees rooted at each number to get the answer.
 *
 * Key constraints:
 *   - All arr[i] are unique, >= 2, and up to 1e9.
 *   - We seek the total ways to arrange binary trees (not a single tree).
 */

/*
 * High-Level Summary:
 * ----
 * We'll use dynamic programming paired with sorting.
 *
 * 1. Sort arr, so that for each number x, all its possible factors (less than
 *    or equal to sqrt(x)) have been processed.
 * 2. For each x in arr, dp[x] will store the total number of binary trees with
 *    root x.
 * 3. For x, try all possible pairs (a, b) such that a * b = x, where both a
 *    and b are in arr. For every such pair, the count of trees with root x
 *    increases by dp[a] * dp[b] (if a == b, only count once, else twice since
 * (a,b) and (b,a) are distinct as left/right subtrees). Don't forget: each root
 * by itself (singleton, i.e., just x) is a valid tree.
 * 4. Return the sum of all dp[x] for x in arr, modulo 1e9+7.
 *
 * Main Data Structures:
 *   - unordered_map<int, long> dp to store tree count for each value.
 *   - unordered_set for fast look-up (see code).
 *
 * Time Complexity: O(N^2), where N is the length of arr (at most 1000).
 * Space Complexity: O(N), for dp and index structures.
 */

// Modular constant as required by the problem.
const int MOD = 1e9 + 7;

class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    // Helper function: Builds the DP count for trees rooted at each number.
    auto buildDP = [&](const vector<int> &arr) -> long long {
      // dp[x] = number of binary trees where x is the root.
      unordered_map<int, long long> dp;
      // For quick lookup if a number is present in arr.
      unordered_map<int, int> idx_map;
      for (int i = 0; i < arr.size(); ++i) {
        idx_map[arr[i]] = i;
      }
      // Start: each number itself is a valid single-node tree.
      for (int x : arr) {
        dp[x] = 1;
      }
      // Iterate each x as root, in increasing order for correctness.
      for (int i = 0; i < arr.size(); ++i) {
        int x = arr[i];
        // Try each a <= sqrt(x) where x % a == 0 and a is present.
        for (int j = 0; j < i; ++j) {
          int a = arr[j];
          if (x % a != 0)
            continue; // a cannot be a left child.
          // quit when a is greater than the square root of x
          if (a > sqrt(x))
            break;
          int b = x / a;
          // b must also be in arr, and (a, b) is an unordered split.
          if (idx_map.count(b)) {
            // If a == b, only one arrangement (avoid double-counting).
            if (a == b) {
              dp[x] = (dp[x] + (dp[a] * dp[b]) % MOD) % MOD;
            } else {
              // Two arrangements: (a,b) left-right and (b,a)
              dp[x] = (dp[x] + (dp[a] * dp[b] * 2) % MOD) % MOD;
            }
          }
        }
      }
      // Sum the counts for all numbers as potential roots.
      long long result = 0;
      for (const auto &x : arr) {
        result = (result + dp[x]) % MOD;
      }
      return result;
    };

    // Safety: Sort arr so that all possible factors processed before larger x.
    std::sort(arr.begin(), arr.end());

    // Call the main DP builder and return the answer.
    return static_cast<int>(buildDP(arr));
  }
};
// @lc code=end
