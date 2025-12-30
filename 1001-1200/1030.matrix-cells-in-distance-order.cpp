/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
class Solution {
public:
  // Returns all cells in the matrix sorted by their Manhattan distance from
  // (rCenter, cCenter)
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    vector<vector<int>> result;
    // Collect all cell coordinates in the matrix
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        result.push_back({r, c});
      }
    }
    // Sort the cells by their Manhattan distance to (rCenter, cCenter)
    sort(result.begin(), result.end(),
         [&](const vector<int> &a, const vector<int> &b) {
           // Calculate Manhattan distance for cell a
           int da = abs(a[0] - rCenter) + abs(a[1] - cCenter);
           // Calculate Manhattan distance for cell b
           int db = abs(b[0] - rCenter) + abs(b[1] - cCenter);
           // Sort in increasing order of distance
           return da < db;
         });
    return result;
  }
};
// @lc code=end
