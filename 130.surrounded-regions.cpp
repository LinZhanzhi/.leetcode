/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    // INSERT_YOUR_CODE
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();

    // Helper lambda for DFS
    auto dfs = [&](int i, int j, auto &&dfs_ref) -> void {
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
        return;
      board[i][j] = '#'; // Mark as visited and safe
      dfs_ref(i + 1, j, dfs_ref);
      dfs_ref(i - 1, j, dfs_ref);
      dfs_ref(i, j + 1, dfs_ref);
      dfs_ref(i, j - 1, dfs_ref);
    };

    // Mark all 'O's on the border and their connected 'O's as safe
    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O')
        dfs(i, 0, dfs);
      if (board[i][n - 1] == 'O')
        dfs(i, n - 1, dfs);
    }
    for (int j = 0; j < n; ++j) {
      if (board[0][j] == 'O')
        dfs(0, j, dfs);
      if (board[m - 1][j] == 'O')
        dfs(m - 1, j, dfs);
    }

    // Flip all remaining 'O's to 'X', and all '#' back to 'O'
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '#') {
          board[i][j] = 'O';
        }
      }
    }
  }
};
// @lc code=end
