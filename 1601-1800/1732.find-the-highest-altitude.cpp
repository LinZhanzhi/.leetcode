/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int max_altitude = 0;
    int current_altitude = 0;
    for (int g : gain) {
      current_altitude += g;
      if (current_altitude > max_altitude) {
        max_altitude = current_altitude;
      }
    }
    return max_altitude;
  }
};
// @lc code=end
