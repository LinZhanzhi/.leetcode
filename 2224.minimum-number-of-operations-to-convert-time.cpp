/*
 * @lc app=leetcode id=2224 lang=cpp
 *
 * [2224] Minimum Number of Operations to Convert Time
 */

// @lc code=start
class Solution {
public:
  int convertTime(string current, string correct) {
    int curH = stoi(current.substr(0, 2));
    int curM = stoi(current.substr(3, 2));
    int corH = stoi(correct.substr(0, 2));
    int corM = stoi(correct.substr(3, 2));
    int curTotal = curH * 60 + curM;
    int corTotal = corH * 60 + corM;
    int diff = corTotal - curTotal;
    int ops = 0;
    int steps[4] = {60, 15, 5, 1};
    for (int i = 0; i < 4; ++i) {
      ops += diff / steps[i];
      diff %= steps[i];
    }
    return ops;
  }
};
// @lc code=end
