/*
 * @lc app=leetcode id=2946 lang=cpp
 *
 * [2946] Matrix Similarity After Cyclic Shifts
 */

// @lc code=start
class Solution {
public:
  bool areSimilar(vector<vector<int>> &mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; ++i) {
      int shift = k % n;
      for (int j = 0; j < n; ++j) {
        int orig_j;
        if (i % 2 == 0) {
          // even-indexed row: left shift
          orig_j = (j + shift) % n;
        } else {
          // odd-indexed row: right shift
          orig_j = (j - shift + n) % n;
        }
        if (mat[i][j] != mat[i][orig_j]) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
