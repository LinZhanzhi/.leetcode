/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int totalTime = 0;
    for (int i = 1; i < points.size(); ++i) {
      int dx = abs(points[i][0] - points[i - 1][0]);
      int dy = abs(points[i][1] - points[i - 1][1]);
      totalTime += max(dx, dy);
    }
    return totalTime;
  }
};
// @lc code=end
