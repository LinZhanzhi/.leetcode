/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    int maxdoubleArea = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int x3 = points[k][0], y3 = points[k][1];
          // Shoelace formula for area of triangle
          // avoid comparison of double, use int instead, divide by 2 at the end
          int doublearea =
              abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
          if (doublearea > maxdoubleArea)
            maxdoubleArea = doublearea;
        }
      }
    }
    return maxdoubleArea / 2.0;
  }
};
// @lc code=end
