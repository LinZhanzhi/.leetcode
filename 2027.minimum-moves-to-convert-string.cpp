/*
 * @lc app=leetcode id=2027 lang=cpp
 *
 * [2027] Minimum Moves to Convert String
 */

// @lc code=start
class Solution {
public:
  int minimumMoves(string s) {
    int moves = 0;
    int i = 0;
    int n = s.length();
    while (i < n) {
      if (s[i] == 'X') {
        moves++;
        i += 3;
      } else {
        i++;
      }
    }
    return moves;
  }
};
// @lc code=end
