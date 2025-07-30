/*
 * @lc app=leetcode id=3222 lang=cpp
 *
 * [3222] Find the Winning Player in Coin Game
 */

// @lc code=start
class Solution {
public:
  string winningPlayer(int x, int y) {
    // The player must pick coins totaling 115 each turn.
    // Only possible way: 1x75 + 4x10 = 115
    // So, each turn, must remove 1 x 75-coin and 4 x 10-coin.
    // The number of possible turns is min(x, y/4)
    // Alice starts, so if number of turns is odd, Alice wins; else Bob wins.

    int turns = min(x, y / 4);
    return (turns % 2 == 1) ? "Alice" : "Bob";
  }
};
// @lc code=end
