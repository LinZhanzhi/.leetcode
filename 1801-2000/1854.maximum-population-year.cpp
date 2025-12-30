/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
class Solution {
public:
  int maximumPopulation(vector<vector<int>> &logs) {
    // INSERT_YOUR_CODE
    // We use a difference array to efficiently compute population per year
    int years[101] = {0}; // years[0] corresponds to 1950, years[100] to 2050
    for (const auto &log : logs) {
      years[log[0] - 1950] += 1;
      years[log[1] - 1950] -= 1;
    }
    int maxPop = 0, currPop = 0, resYear = 1950;
    for (int i = 0; i < 101; ++i) {
      currPop += years[i];
      if (currPop > maxPop) {
        maxPop = currPop;
        resYear = 1950 + i;
      }
    }
    return resYear;
  }
};
// @lc code=end
