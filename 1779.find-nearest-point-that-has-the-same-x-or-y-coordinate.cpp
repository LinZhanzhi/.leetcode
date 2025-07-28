/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */

// @lc code=start
class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int minDist = INT_MAX;
    int idx = -1;
    for (int i = 0; i < points.size(); ++i) {
      int xi = points[i][0];
      int yi = points[i][1];
      if (xi == x || yi == y) {
        int dist = abs(x - xi) + abs(y - yi);
        if (dist < minDist) {
          minDist = dist;
          idx = i;
        }
      }
    }
    return idx;
  }
};
// @lc code=end
