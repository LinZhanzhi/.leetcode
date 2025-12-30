/*
 * @lc app=leetcode id=2678 lang=cpp
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
class Solution {
public:
  int countSeniors(vector<string> &details) {
    int count = 0;
    for (const string &s : details) {
      int age = (s[11] - '0') * 10 + (s[12] - '0');
      if (age > 60) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
