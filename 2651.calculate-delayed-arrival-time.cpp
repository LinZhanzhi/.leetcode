/*
 * @lc app=leetcode id=2651 lang=cpp
 *
 * [2651] Calculate Delayed Arrival Time
 */

// @lc code=start
class Solution {
public:
  int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
  }
};
// @lc code=end
