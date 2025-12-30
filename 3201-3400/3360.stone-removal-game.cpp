/*
 * @lc app=leetcode id=3360 lang=cpp
 *
 * [3360] Stone Removal Game
 */

// @lc code=start
class Solution {
public:
  bool canAliceWin(int n) {
    if (n < 10)
      return false;
    int stones = n;
    int last = 10;
    bool aliceTurn = false; // Alice has already played first move
    stones -= 10;
    int prev = 10;
    while (stones > 0) {
      int take = prev - 1;
      if (take <= 0 || stones < take) {
        // Current player cannot move, so previous player wins
        return !aliceTurn;
      }
      stones -= take;
      prev = take;
      aliceTurn = !aliceTurn;
    }
    // If stones == 0 after a move, current player wins
    return !aliceTurn;
  }
};
// @lc code=end
