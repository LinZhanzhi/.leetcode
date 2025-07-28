/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution {
public:
  bool checkOnesSegment(string s) {
    // We look for more than one segment of '1's by checking if there is a '0'
    // followed by a '1'
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] == '0' && s[i] == '1') {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
