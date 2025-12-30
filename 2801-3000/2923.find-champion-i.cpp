/*
 * @lc app=leetcode id=2923 lang=cpp
 *
 * [2923] Find Champion I
 */

// @lc code=start
class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      bool isChampion = true;
      for (int j = 0; j < n; ++j) {
        if (i != j && grid[j][i] == 1) {
          isChampion = false;
          break;
        }
      }
      if (isChampion)
        return i;
    }
    return -1; // Should not reach here as per problem constraints
  }
};
// @lc code=end
