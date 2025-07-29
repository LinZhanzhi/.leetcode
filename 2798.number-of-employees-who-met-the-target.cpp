/*
 * @lc app=leetcode id=2798 lang=cpp
 *
 * [2798] Number of Employees Who Met the Target
 */

// @lc code=start
class Solution {
public:
  int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
    int count = 0;
    for (int h : hours) {
      if (h >= target) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
