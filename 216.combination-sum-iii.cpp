/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to find all unique combinations of exactly k numbers (from 1 to
 * 9, each used at most once) that add up to a target sum n. Each combination
 * must have k distinct numbers, and the order of numbers in a combination does
 * not matter (so [1,2,4] is the same as [2,1,4]). We need to return all such
 * possible combinations, or an empty list if none exist.
 *
 * High-Level Summary:
 * ----
 * We use a backtracking (depth-first search) approach to explore all possible
 * combinations of numbers 1-9. At each step, we decide whether to include the
 * current number in our combination. We keep track of the current combination,
 * the sum so far, and the number of elements chosen. If we reach k numbers and
 * the sum is exactly n, we add the combination to the result. We prune the
 * search if the sum exceeds n or if we've chosen more than k numbers. The
 * algorithm ensures each number is used at most once and avoids duplicates by
 * always moving forward in the number range.
 *
 * Time Complexity: O(C(9, k)), since we are choosing k numbers from 9.
 * Space Complexity: O(C(9, k)), for storing the results and the recursion
 * stack.
 */

#include <vector> // Include vector for using std::vector
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find all valid combinations
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result; // To store all valid combinations
    vector<int> current;        // To store the current combination being built
    backtrack(1, k, n, current, result); // Start backtracking from number 1
    return result;
  }

private:
  // Helper function for backtracking
  // start: the current number to consider (to ensure each number is used at
  // most once and combinations are unique) k: how many numbers we still need to
  // pick n: the remaining sum we need to reach current: the current combination
  // being built result: the list of all valid combinations found so far
  void backtrack(int start, int k, int n, vector<int> &current,
                 vector<vector<int>> &result) {
    // If we've picked k numbers
    if (current.size() == k) {
      // If their sum is exactly n, add a copy of current to result
      if (n == 0) {
        result.push_back(current);
      }
      // Whether or not we found a valid sum, we can't pick more numbers, so
      // return
      return;
    }
    // Try each number from 'start' to 9
    for (int i = start; i <= 9; ++i) {
      // If the current number is greater than the remaining sum, no need to
      // continue (prune the search)
      if (i > n)
        break;
      // Choose the current number
      current.push_back(i);
      // Recurse with updated parameters:
      // - next start is i+1 (so each number is used at most once and
      // combinations are unique)
      // - k remains the same (we check current.size() for how many picked)
      // - n is reduced by i (since we've used i)
      backtrack(i + 1, k, n - i, current, result);
      // Backtrack: remove the last number to try the next possibility
      current.pop_back();
    }
  }
};
// @lc code=end
