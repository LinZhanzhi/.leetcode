/*
 * @lc app=leetcode id=2446 lang=cpp
 *
 * [2446] Determine if Two Events Have Conflict
 */

// @lc code=start
class Solution {
public:
  bool haveConflict(vector<string> &event1, vector<string> &event2) {
    auto toMinutes = [](const string &t) {
      return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
    };
    int s1 = toMinutes(event1[0]), e1 = toMinutes(event1[1]);
    int s2 = toMinutes(event2[0]), e2 = toMinutes(event2[1]);
    return !(e1 < s2 || e2 < s1);
  }
};
// @lc code=end
