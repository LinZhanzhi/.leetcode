/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */

// @lc code=start

#include <vector>  // To use std::vector for array inputs
using std::vector; // For vector shorthand

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding out how many unique ordered triples (i, j, k)
 * in a given array such that i < j < k and the sum of the numbers at those
 * positions equals the target. Duplicates in the array matter, so combinations
 * involving equal numbers must be counted properly—it's a counting/multiplicity
 * problem, not a distinct elements problem.
 *
 * Key constraints: the array values range from 0 to 100, so
 * we can use counting/combination techniques rather than brute force.
 *
 * The result should be returned modulo 1e9+7 because the count could be large.
 *
 * High-Level Summary:
 * ----
 * The main approach here is to count how many times each possible value occurs
 * in the input array, using an array of counts since values range from 0 to
 * 100. Then, we enumerate through all possible triplets (x, y, z) with 0 <= x
 * <= y <= z <= 100 and x + y + z == target. For each such triplet, calculate
 * the number of (i, j, k) that map to those values using combinatorics:
 *   - If x, y, z are all distinct: count[x] * count[y] * count[z]
 *   - If some values are the same, use combinations (nCk).
 * This way, we avoid O(n^3) enumeration and leverage frequency for O(1)
 * computation per possible value triple.
 *
 * Time complexity: O(101^2) = O(10,000), since we check all (x, y, z) with x <=
 * y <= z. Space complexity: O(1) extra (apart from count array of size 101).
 */

// Define the modulo as a constant for easy reuse
const int MOD = 1e9 + 7;

class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    // Step 1: Count frequencies of each possible number (0 to 100)
    vector<long long> count(101, 0); // Use long long for large counts

    // Fill the frequency table
    for (int num : arr) {
      count[num]++;
    }

    // Step 2: Enumerate ordered triplets (x, y, z) where x <= y <= z
    long long result = 0;
    for (int x = 0; x <= 100; ++x) {
      if (count[x] == 0)
        continue; // Skip impossible
      for (int y = x; y <= 100; ++y) {
        if (count[y] == 0)
          continue;
        int z = target - x - y;
        // Ensure 0 <= z <= 100 and z >= y for order and valid index
        if (z < y || z > 100)
          continue;
        if (count[z] == 0)
          continue;

        // Case 1: x, y, z are all different
        if (x < y && y < z) {
          // Each must be chosen from count[x], count[y], count[z]
          result = (result + count[x] * count[y] * count[z]) % MOD;
        }
        // Case 2: x == y < z
        else if (x == y && y < z) {
          // For x == y, pick two out of count[x], times count[z]
          // Number of ways to pick two: count[x] * (count[x] - 1) / 2
          long long ways = (count[x] * (count[x] - 1) / 2) * count[z];
          result = (result + ways) % MOD;
        }
        // Case 3: x < y == z
        else if (x < y && y == z) {
          // For y == z, pick two out of count[y], times count[x]
          long long ways = count[x] * (count[y] * (count[y] - 1) / 2);
          result = (result + ways) % MOD;
        }
        // Case 4: x == y == z
        else if (x == y && y == z) {
          // All three are the same, pick 3 out of count[x]
          // Number of ways: count[x] * (count[x]-1) * (count[x]-2) / 6
          long long ways = count[x] * (count[x] - 1) * (count[x] - 2) / 6;
          result = (result + ways) % MOD;
        }
        // No other cases, since we enforce x <= y <= z
      }
    }
    // Return the result modulo 1e9+7 as per problem constraint
    return static_cast<int>(result);
  }
};
// @lc code=end
