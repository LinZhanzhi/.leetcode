/*
 * @lc app=leetcode id=2643 lang=cpp
 *
 * [2643] Row With Maximum Ones
 */

// @lc code=start
class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int maxOnes = 0;
    int rowIdx = 0;
    for (int i = 0; i < mat.size(); ++i) {
      int ones = 0;
      for (int j = 0; j < mat[i].size(); ++j) {
        if (mat[i][j] == 1)
          ++ones;
      }
      if (ones > maxOnes) {
        maxOnes = ones;
        rowIdx = i;
      }
    }
    return {rowIdx, maxOnes};
  }
};
// @lc code=end
