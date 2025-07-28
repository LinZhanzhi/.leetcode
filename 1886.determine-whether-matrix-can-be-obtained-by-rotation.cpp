/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    int n = mat.size();
    bool same[4] = {true, true, true, true};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] != target[i][j])
          same[0] = false; // 0 degree
        if (mat[i][j] != target[j][n - 1 - i])
          same[1] = false; // 90 degree
        if (mat[i][j] != target[n - 1 - i][n - 1 - j])
          same[2] = false; // 180 degree
        if (mat[i][j] != target[n - 1 - j][i])
          same[3] = false; // 270 degree
      }
    }
    return same[0] || same[1] || same[2] || same[3];
  }
};
// @lc code=end
