/*
 * @lc app=leetcode id=1450 lang=cpp
 *
 * [1450] Number of Students Doing Homework at a Given Time
 */

// @lc code=start
class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int count = 0;
    for (int i = 0; i < startTime.size(); ++i) {
      if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
