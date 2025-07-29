/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start
class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int n = grid.size();
    int N = n * n;
    vector<int> count(N + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        count[grid[i][j]]++;
      }
    }
    int repeated = -1, missing = -1;
    for (int i = 1; i <= N; ++i) {
      if (count[i] == 2)
        repeated = i;
      else if (count[i] == 0)
        missing = i;
    }
    return {repeated, missing};
  }
};
// @lc code=end
