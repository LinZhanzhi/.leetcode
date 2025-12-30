/*
 * @lc app=leetcode id=3184 lang=cpp
 *
 * [3184] Count Pairs That Form a Complete Day I
 */

// @lc code=start
class Solution {
public:
  int countCompleteDayPairs(vector<int> &hours) {
    int n = hours.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((hours[i] + hours[j]) % 24 == 0) {
          ++res;
        }
      }
    }
    return res;
  }
};
// @lc code=end
