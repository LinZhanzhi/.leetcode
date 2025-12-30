/*
 * @lc app=leetcode id=2960 lang=cpp
 *
 * [2960] Count Tested Devices After Test Operations
 */

// @lc code=start
class Solution {
public:
  int countTestedDevices(vector<int> &batteryPercentages) {
    int n = batteryPercentages.size();
    int tested = 0;
    for (int i = 0; i < n; ++i) {
      if (batteryPercentages[i] > 0) {
        ++tested;
        for (int j = i + 1; j < n; ++j) {
          if (batteryPercentages[j] > 0) {
            batteryPercentages[j]--;
          }
        }
      }
    }
    return tested;
  }
};
// @lc code=end
