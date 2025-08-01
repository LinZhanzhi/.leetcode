/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
      if (k == word.size())
        return true;
      if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
      if (board[i][j] != word[k])
        return false;

      char temp = board[i][j];
      board[i][j] = '#'; // mark as visited

      bool found = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) ||
                   dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);

      board[i][j] = temp; // restore

      return found;
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(i, j, 0))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end
