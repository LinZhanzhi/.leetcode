/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given an array where each element is a unique integer from 0 to n-1, we can
 * form a sequence starting at any index k by repeatedly following the value at
 * the current index as the next index. This forms a chain (or cycle) until we
 * revisit an index we've already seen. The task is to find the length of the
 * longest such chain (set) that can be formed from any starting index.
 *
 * High-Level Summary:
 * ----
 * The solution iterates through each index in the array, and for each index,
 * follows the chain of indices as described, counting the length until a repeat
 * is found. To avoid redundant work, we mark indices as visited so that we
 * never process the same cycle twice. This ensures each element is visited at
 * most once, making the algorithm efficient. The main loop keeps track of the
 * maximum chain length found. Time complexity is O(n), and space complexity is
 * O(n) for the visited array.
 *
 */

/*
 * Is there always a cycle when following the sequence from nums[k]?
 * ----
 * Yes, there must always be a cycle when following the sequence as described in
 * this problem.
 *
 * Proof:
 * - The array nums has length n, and each element is a unique integer from 0 to
 * n-1 (i.e., nums is a permutation of [0, 1, ..., n-1]).
 * - If we start at any index k and repeatedly set k = nums[k], we are always
 * moving to another valid index in the array.
 * - Since there are only n possible indices and each value is unique, the
 * sequence cannot visit the same index twice until it returns to a previously
 * visited index.
 * - By the Pigeonhole Principle, after at most n steps, we must revisit an
 * index (since there are only n indices).
 * - Once we revisit an index, the sequence will repeat in the same way as
 * before, forming a cycle.
 * - In fact, since nums is a permutation, the array can be decomposed into one
 * or more disjoint cycles that together cover all indices.
 * - Therefore, starting from any index and following the sequence will always
 * eventually form a cycle.
 *
 * This property is what allows the solution to mark visited indices and avoid
 * redundant work, since every index belongs to exactly one cycle.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // Main function to find the longest set s[k] as described in the problem
  int arrayNesting(vector<int> &nums) {
    // Get the size of the input array
    int n = nums.size();
    // Create a boolean vector to keep track of visited indices
    vector<bool> visited(n, false);
    // Variable to store the maximum length found
    int maxLen = 0;

    // Iterate through each index in the array
    for (int i = 0; i < n; ++i) {
      // If this index has not been visited, start a new chain from here
      if (!visited[i]) {
        // Compute the length of the chain starting from index i
        int len = computeChainLength(nums, visited, i);
        // Update the maximum length if this chain is longer
        if (len > maxLen) {
          maxLen = len;
        }
      }
      // If already visited, skip to avoid redundant work
    }
    // Return the maximum chain length found
    return maxLen;
  }

private:
  // Helper function to compute the length of the chain starting from index
  // start
  int computeChainLength(const vector<int> &nums, vector<bool> &visited,
                         int start) {
    int count = 0;
    int current = start;
    // Follow the chain until we revisit an index
    while (!visited[current]) {
      // Mark the current index as visited
      visited[current] = true;
      // Move to the next index in the chain
      current = nums[current];
      // Increment the count for each unique index visited
      ++count;
    }
    // Return the total length of this chain
    return count;
  }
};
// @lc code=end
