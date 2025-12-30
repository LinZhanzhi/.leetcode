/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += mat[i][i];
      if (i != n - 1 - i) {
        sum += mat[i][n - 1 - i];
      }
    }
    return sum;
  }
};
// @lc code=end
