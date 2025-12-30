/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    vector<int> xs;
    for (const auto &p : points) {
      xs.push_back(p[0]);
    }
    sort(xs.begin(), xs.end());
    int max_width = 0;
    for (int i = 1; i < xs.size(); ++i) {
      max_width = max(max_width, xs[i] - xs[i - 1]);
    }
    return max_width;
  }
};
// @lc code=end
