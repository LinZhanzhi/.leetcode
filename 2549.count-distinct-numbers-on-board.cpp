/*
 * @lc app=leetcode id=2549 lang=cpp
 *
 * [2549] Count Distinct Numbers on Board
 */

// The problem is a bit confusing at first glance, so let's break it down:
//
// - You start with a single number n on the board.
// - Every day, for each number x currently on the board, you look for all
// numbers i (1 <= i <= n) such that x % i == 1.
// - For every such i, you add i to the board (if it's not already there).
// - Once a number is on the board, it stays forever.
// - You repeat this process for a huge number of days (10^9), but in practice,
// the board will stop changing after a few days.
//
// Let's see what happens with an example, n = 5:
//   Day 0: [5]
//   Day 1: For x=5, 5%2==1 and 5%4==1, so add 2 and 4. Now board: [2,4,5]
//   Day 2: For x=2, 2%1==0, 2%2==0 (no new numbers)
//           For x=4, 4%3==1, so add 3. Now board: [2,3,4,5]
//           For x=5, already checked
//   Day 3: For x=3, 3%2==1, so add 2 (already present)
//           For x=2, x=4, x=5: no new numbers
//   So after a few days, the board stops growing. The answer is the number of
//   distinct numbers on the board.
//
// Observation:
//   - For n == 1, only 1 is ever on the board.
//   - For n > 1, you can always reach every number from 2 to n, but never 1
//   (since x % 1 == 0 for any x).
//   - So the answer is n-1 for n > 1, and 1 for n == 1.
//
// Implementation:
class Solution {
public:
  int distinctIntegers(int n) {
    // If n == 1, only 1 is on the board
    if (n == 1)
      return 1;
    // Otherwise, all numbers from 2 to n will eventually be on the board
    return n - 1;
  }
};
// @lc code=end
