/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    if (start > destination)
      std::swap(start, destination);
    int total = 0, path = 0;
    for (int i = 0; i < distance.size(); ++i) {
      total += distance[i];
      if (i >= start && i < destination) {
        path += distance[i];
      }
    }
    return std::min(path, total - path);
  }
};
// @lc code=end
