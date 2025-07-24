/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

// @lc code=start
class Solution {
public:
  bool divisorGame(int n) {
    // Alice wins if and only if n is even.
    /*
      Proof:
      - If n is even, Alice can always subtract 1 (which is a divisor of n),
      making n odd for Bob.
      - Whenever Bob gets an odd number, any divisor x (1 <= x < n) must also be
      odd, so n-x is even again for Alice.
      - This way, Alice can always give Bob an odd number, and Bob can only give
      Alice an even number.
      - When n becomes 1 (odd), the player to move loses (cannot make a move).
      - Therefore, Alice wins if and only if n is even at the start.
    */
    return n % 2 == 0;
  }
};
// @lc code=end
