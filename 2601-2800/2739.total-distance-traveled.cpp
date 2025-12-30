/*
 * @lc app=leetcode id=2739 lang=cpp
 *
 * [2739] Total Distance Traveled
 */

// @lc code=start
class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int distance = 0;
    while (mainTank > 0) {
      if (mainTank >= 5) {
        int use = 5;
        distance += use * 10;
        mainTank -= use;
        if (additionalTank > 0) {
          mainTank += 1;
          additionalTank -= 1;
        }
      } else {
        distance += mainTank * 10;
        mainTank = 0;
      }
    }
    return distance;
  }
};
// @lc code=end
