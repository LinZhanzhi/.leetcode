/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int m = image.size();
    int n = image[0].size();
    int originalColor = image[sr][sc];
    if (originalColor == color)
      return image;

    // Helper lambda for DFS
    function<void(int, int)> dfs = [&](int r, int c) {
      if (r < 0 || r >= m || c < 0 || c >= n)
        return;
      if (image[r][c] != originalColor)
        return;
      image[r][c] = color;
      dfs(r + 1, c);
      dfs(r - 1, c);
      dfs(r, c + 1);
      dfs(r, c - 1);
    };

    dfs(sr, sc);
    return image;
  }
};
// @lc code=end
