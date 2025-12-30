/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start
class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    int rows[3] = {0}, cols[3] = {0}, diag = 0, anti_diag = 0;
    int n = moves.size();
    for (int i = 0; i < n; ++i) {
      int player = (i % 2 == 0) ? 1 : -1; // A: 1, B: -1
      int r = moves[i][0], c = moves[i][1];
      rows[r] += player;
      cols[c] += player;
      if (r == c)
        diag += player;
      if (r + c == 2)
        anti_diag += player;
      if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag) == 3 ||
          abs(anti_diag) == 3) {
        return player == 1 ? "A" : "B";
      }
    }
    if (n == 9)
      return "Draw";
    return "Pending";
  }
};
// @lc code=end
