/*
 * @lc app=leetcode id=3274 lang=cpp
 *
 * [3274] Check if Two Chessboard Squares Have the Same Color
 */

// @lc code=start
class Solution {
public:
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    // INSERT_YOUR_CODE
    auto getColor = [](const string &coord) {
      int col = coord[0] - 'a';
      int row = coord[1] - '1';
      return (col + row) % 2;
    };
    return getColor(coordinate1) == getColor(coordinate2);
  }
};
// @lc code=end
