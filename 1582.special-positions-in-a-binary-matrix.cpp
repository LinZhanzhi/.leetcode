/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int count = 0;

    // Instead of storing rowSum and colSum arrays, count on the fly to save
    // memory
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          // Check if this is the only 1 in its row
          bool onlyOneInRow = true;
          for (int k = 0; k < n; ++k) {
            if (k != j && mat[i][k] == 1) {
              onlyOneInRow = false;
              break;
            }
          }
          if (!onlyOneInRow)
            continue;

          // Check if this is the only 1 in its column
          bool onlyOneInCol = true;
          for (int k = 0; k < m; ++k) {
            if (k != i && mat[k][j] == 1) {
              onlyOneInCol = false;
              break;
            }
          }
          if (onlyOneInCol)
            ++count;
        }
      }
    }
    return count;
  }
};
// @lc code=end
