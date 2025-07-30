/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int total_apples = 0;
    for (int a : apple)
      total_apples += a;
    sort(capacity.rbegin(), capacity.rend());
    int sum = 0, cnt = 0;
    for (int c : capacity) {
      sum += c;
      cnt++;
      if (sum >= total_apples)
        return cnt;
    }
    return cnt; // Should never reach here due to constraints
  }
};
// @lc code=end
