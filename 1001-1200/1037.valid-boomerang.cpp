/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
class Solution {
public:
  bool isBoomerang(vector<vector<int>> &points) {
    // Check if all points are distinct
    if (points[0] == points[1] || points[0] == points[2] ||
        points[1] == points[2]) {
      return false;
    }
    // Check if the three points are colinear
    // Use the area of triangle formula: (x1(y2-y3) + x2(y3-y1) + x3(y1-y2)) ==
    // 0
    int x1 = points[0][0], y1 = points[0][1];
    int x2 = points[1][0], y2 = points[1][1];
    int x3 = points[2][0], y3 = points[2][1];
    // The area is zero if the points are colinear
    if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
      return false;
    }
    return true;
  }
};
// @lc code=end
