/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
  bool canWinNim(int n) {
    // If n is divisible by 4, the second player can always win
    // by taking the remaining stones after the first player's move
    return n % 4 != 0;
  }
};
// @lc code=end
