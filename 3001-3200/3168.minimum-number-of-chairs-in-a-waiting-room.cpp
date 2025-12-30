/*
 * @lc app=leetcode id=3168 lang=cpp
 *
 * [3168] Minimum Number of Chairs in a Waiting Room
 */

// @lc code=start
class Solution {
public:
  int minimumChairs(string s) {
    int curr = 0, maxChairs = 0;
    for (char c : s) {
      if (c == 'E') {
        curr++;
        if (curr > maxChairs)
          maxChairs = curr;
      } else if (c == 'L') {
        curr--;
      }
    }
    return maxChairs;
  }
};
// @lc code=end
