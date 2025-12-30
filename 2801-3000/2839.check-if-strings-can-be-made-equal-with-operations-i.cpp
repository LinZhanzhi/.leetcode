/*
 * @lc app=leetcode id=2839 lang=cpp
 *
 * [2839] Check if Strings Can be Made Equal With Operations I
 */

// @lc code=start
class Solution {
public:
  bool canBeEqual(string s1, string s2) {
    // We can only swap (0,2) and (1,3) in any string any number of times.
    // That means, positions 0 and 2 can be permuted among themselves, and 1 and
    // 3 among themselves. So, for s1 to be made equal to s2, the multiset of
    // chars at (0,2) must match, and (1,3) must match.

    return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
            (s1[0] == s2[2] && s1[2] == s2[0])) &&
           ((s1[1] == s2[1] && s1[3] == s2[3]) ||
            (s1[1] == s2[3] && s1[3] == s2[1]));
  }
};
// @lc code=end
