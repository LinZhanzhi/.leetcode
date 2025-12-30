/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    if (timeSeries.empty() || duration == 0)
      return 0;
    int total = 0;
    for (int i = 1; i < timeSeries.size(); ++i) {
      total += std::min(duration, timeSeries[i] - timeSeries[i - 1]);
    }
    total += duration; // Add duration for the last attack
    return total;
  }
};
// @lc code=end
