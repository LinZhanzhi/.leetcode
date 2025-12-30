/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

/*
 * Brief, Digested Understanding:
 * ----
 * In this problem, two players take turns picking unique numbers from 1 to
 * maxChoosableInteger, each adding their pick to a running total. The first
 * player to reach or exceed desiredTotal wins. The challenge is to determine if
 * the first player can guarantee a win, assuming both play optimally and no
 * number can be picked more than once.
 *
 * The core idea is to simulate all possible choices and see if the first player
 * can always force a win, regardless of how the second player responds.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses recursion with memoization (top-down dynamic programming)
 * to explore all possible game states. Each state is defined by the set of
 * numbers already chosen (represented as a bitmask) and the current total. For
 * each possible pick, we check if picking that number immediately wins the
 * game, or if it forces the opponent into a losing position. If any pick leads
 * to a win for the current player, we return true for that state.
 *
 * To optimize, we use a hash map to memoize results for each state (bitmask),
 * avoiding redundant calculations. We also handle edge cases: if the sum of all
 * numbers is less than desiredTotal, no one can win.
 *
 * Time Complexity: O(2^N * N), where N = maxChoosableInteger (since there are
 * 2^N possible states and up to N choices per state). Space Complexity: O(2^N)
 * for memoization.
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to determine if the first player can force a win
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // Edge case: If the desired total is 0 or less, first player wins by
    // default
    if (desiredTotal <= 0)
      return true;

    // Calculate the sum of all choosable numbers
    int maxSum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
    // If the sum of all numbers is less than desiredTotal, it's impossible to
    // reach the target
    if (maxSum < desiredTotal)
      return false;

    // Memoization map: key is the bitmask representing used numbers, value is
    // whether the current player can win
    unordered_map<int, bool> memo;

    // Start the recursive search with no numbers used (bitmask = 0) and the
    // initial desiredTotal
    return canWinHelper(maxChoosableInteger, desiredTotal, 0, memo);
  }

private:
  // Helper function to recursively determine if the current player can win
  // Parameters:
  //   maxChoosableInteger: the largest number that can be chosen
  //   desiredTotal: the remaining total needed to win
  //   usedNumbers: bitmask representing which numbers have been used (1 = used)
  //   memo: memoization map to cache results for each state
  bool canWinHelper(int maxChoosableInteger, int desiredTotal, int usedNumbers,
                    unordered_map<int, bool> &memo) {
    // If this state has been computed before, return the cached result
    if (memo.count(usedNumbers)) {
      return memo[usedNumbers];
    }

    // Try every possible number from 1 to maxChoosableInteger
    for (int i = 1; i <= maxChoosableInteger; ++i) {
      // Compute the bit corresponding to number i (0-based index)
      int curBit = 1 << (i - 1);
      // If this number has already been used, skip it
      if (usedNumbers & curBit)
        continue;

      // If picking this number reaches or exceeds the desiredTotal, current
      // player wins
      if (i >= desiredTotal) {
        memo[usedNumbers] = true;
        return true;
      }

      // Otherwise, simulate picking this number and see if the opponent can win
      // If the opponent cannot win in the next state, current player wins
      if (!canWinHelper(maxChoosableInteger, desiredTotal - i,
                        usedNumbers | curBit, memo)) {
        memo[usedNumbers] = true;
        return true;
      }
    }

    // If no choice leads to a win, current player loses in this state
    memo[usedNumbers] = false;
    return false;
  }
};
// @lc code=end
