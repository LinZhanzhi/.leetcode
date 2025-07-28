/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */

// @lc code=start
class Solution {
public:
  bool squareIsWhite(string coordinates) {
    int col = coordinates[0] - 'a';
    int row = coordinates[1] - '1';
    return (col + row) % 2 == 1;
  }
};
// @lc code=end
