/*
 * @lc app=leetcode id=2432 lang=cpp
 *
 * [2432] The Employee That Worked on the Longest Task
 */

// @lc code=start
class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int maxTime = 0;
    int resId = logs[0][0];
    int prevTime = 0;
    for (const auto &log : logs) {
      int id = log[0];
      int leave = log[1];
      int duration = leave - prevTime;
      if (duration > maxTime) {
        maxTime = duration;
        resId = id;
      } else if (duration == maxTime && id < resId) {
        resId = id;
      }
      prevTime = leave;
    }
    return resId;
  }
};
// @lc code=end
