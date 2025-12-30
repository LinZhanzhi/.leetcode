/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about building a binary grammar sequence row by row. You
 * start with a single symbol "0." Each time you build the next row, every 0 in
 * the previous row turns into "01" and every 1 turns into "10." The question
 * is: given a target row number n and a column k (1-indexed), what is the
 * symbol at that spot, without having to actually build all the gigantic
 * strings?
 *
 * At the heart: Each symbol depends only on its parent cell in the previous
 * row, and there is a predictable pattern of how position k gets mapped back as
 * we recurse to earlier rows.
 *
 * Key constraints: n <= 30, k up to 2^n - 1, so we can't afford to actually
 * construct the entire sequence for big n—must use recursive, mathematical,
 * or bit-manipulation approach.
 *
 * High-Level Summary:
 * ----
 * We'll solve this with a recursive and modular approach! Each symbol in row n
 * is derived from a corresponding parent in row n-1: specifically, symbol k in
 * row n comes from symbol ((k+1)/2) in row n-1. Odd-indexed children (i.e. left
 * child) inherit the value, while even-indexed (right child) "flip" (so 0
 * becomes 1, 1 becomes 0). This is a perfect fit for recursion:
 *   - The base case: n == 1, k == 1 is always 0.
 *   - Otherwise, recursively find the parent and flip if needed.
 * We modularize the recursive computation into a helper function for clarity.
 * Time complexity is O(n), space is O(n) due to the recursion stack.
 */

// @lc code=start
class Solution {
public:
  // Public API that wraps the recursive computation.
  int kthGrammar(int n, int k) {
    // The core logic is isolated in a helper function for modular clarity.
    return kthGrammarHelper(n, k);
  }

private:
  // Recursive helper to determine the symbol at (n, k).
  int kthGrammarHelper(int n, int k) {
    // Base case: The very first symbol in the very first row is always 0.
    if (n == 1 && k == 1) {
      return 0;
    }

    // Find the parent index: every symbol is generated from its ancestor
    // in the previous row. The (k+1)/2 gives the parent's column.
    int parent = kthGrammarHelper(n - 1, (k + 1) / 2);

    // Determine if k is odd or even to decide if we "flip" or retain parent.
    // Odd k: left child (same as parent), even k: right child (flipped).
    if (k % 2 == 1) {
      // k is odd: left child, copy parent's value
      return parent;
    } else {
      // k is even: right child, flip parent's value (0<->1)
      return 1 - parent;
    }
  }
};
// @lc code=end
