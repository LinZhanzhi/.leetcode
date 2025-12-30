/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to generate all numbers from 1 to n, but instead of the
 * usual numeric order, we must list them in lexicographical (dictionary) order,
 * as if the numbers were strings. For example, for n = 13, the order would be:
 * 1, 10, 11, 12, 13, 2, 3, ..., 9. The challenge is to do this efficiently, in
 * O(n) time and with O(1) extra space (not counting the output).
 *
 * High-Level Summary:
 * ----
 * The solution uses a "prefix tree" (trie-like) traversal, but implemented
 * iteratively. We start from 1 and try to go as deep as possible by multiplying
 * by 10 (adding a '0' digit), which corresponds to the next lexicographical
 * number. If we can't go deeper (because the number would exceed n), we
 * increment the current number. If incrementing would cause us to move to the
 * next tens/hundreds place (e.g., from 19 to 20), we repeatedly divide by 10 to
 * backtrack up the tree until we can increment again. This ensures we visit
 * every number in lex order in O(n) time.
 *
 * Time Complexity: O(n) — Each number from 1 to n is visited exactly once.
 * Space Complexity: O(1) extra space — Only a few integer variables are used,
 * not counting the output vector.
 */

#include <vector>  // Include vector for the return type.
using std::vector; // Bring vector into the current namespace.

// @lc code=start
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    // Result vector to store the lexicographical order.
    vector<int> result;
    // Start from the first number in lexicographical order.
    int curr = 1;
    // We need to add n numbers to the result.
    for (int i = 0; i < n; ++i) {
      result.push_back(curr); // Add the current number to the result.

      // Try to go deeper in the "prefix tree" by multiplying by 10.
      // This corresponds to appending a '0' digit, e.g., 1 -> 10, 10 -> 100.
      if (curr * 10 <= n) {
        curr *= 10;
      } else {
        // If we can't go deeper, try to increment to the next number.
        // But if incrementing would cause us to go past n or end with a '9',
        // we need to backtrack up the tree (remove the last digit(s)).
        while (curr % 10 == 9 || curr + 1 > n) {
          curr /= 10; // Move up to the parent prefix.
        }
        curr += 1; // Move to the next lexicographical number.
      }
    }
    return result; // Return the lexicographically ordered numbers.
  }
};
// @lc code=end
