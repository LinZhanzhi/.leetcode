/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    int n = releaseTimes.size();
    int maxDuration = releaseTimes[0];
    char result = keysPressed[0];
    for (int i = 1; i < n; ++i) {
      int duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > maxDuration ||
          (duration == maxDuration && keysPressed[i] > result)) {
        maxDuration = duration;
        result = keysPressed[i];
      }
    }
    return result;
  }
};
// @lc code=end
