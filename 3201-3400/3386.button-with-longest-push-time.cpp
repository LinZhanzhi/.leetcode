/*
 * @lc app=leetcode id=3386 lang=cpp
 *
 * [3386] Button with Longest Push Time
 */

// @lc code=start
class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>> &events) {
    int n = events.size();
    int maxTime = events[0][1];
    int res = events[0][0];
    for (int i = 1; i < n; ++i) {
      int duration = events[i][1] - events[i - 1][1];
      if (duration > maxTime || (duration == maxTime && events[i][0] < res)) {
        maxTime = duration;
        res = events[i][0];
      }
    }
    return res;
  }
};
// @lc code=end
