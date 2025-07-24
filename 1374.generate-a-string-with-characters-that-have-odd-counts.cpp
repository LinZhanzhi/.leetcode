/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
class Solution {
public:
  string generateTheString(int n) {
    if (n % 2 == 1) {
      // If n is odd, we can use 'a' n times
      return string(n, 'a');
    } else {
      // If n is even, use 'a' (n-1) times and 'b' once
      return string(n - 1, 'a') + 'b';
    }
  }
};
// @lc code=end
