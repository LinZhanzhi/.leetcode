/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int n = students.size();
    int count0 = 0, count1 = 0;
    for (int s : students) {
      if (s == 0)
        count0++;
      else
        count1++;
    }
    for (int i = 0; i < n; ++i) {
      if (sandwiches[i] == 0) {
        if (count0 == 0)
          return n - i;
        count0--;
      } else {
        if (count1 == 0)
          return n - i;
        count1--;
      }
    }
    return 0;
  }
};
// @lc code=end
