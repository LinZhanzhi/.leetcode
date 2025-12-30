/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    // INSERT_YOUR_CODE
    // There are at least 2 points, so we can get the direction vector from the
    // first two
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int x1 = coordinates[1][0], y1 = coordinates[1][1];
    int dx = x1 - x0;
    int dy = y1 - y0;
    int n = coordinates.size();
    for (int i = 2; i < n; ++i) {
      int xi = coordinates[i][0], yi = coordinates[i][1];
      // Check if the vector from (x0, y0) to (xi, yi) is colinear with (dx, dy)
      // That is, (xi - x0) * dy == (yi - y0) * dx
      if ((xi - x0) * dy != (yi - y0) * dx) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
