/*
 * @lc app=leetcode id=2609 lang=cpp
 *
 * [2609] Find the Longest Balanced Substring of a Binary String
 */

// @lc code=start
class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    // INSERT_YOUR_CODE
    int maxLen = 0;
    int n = s.size();
    int i = 0;
    while (i < n) {
      int zeroCount = 0, oneCount = 0;
      // Count consecutive 0's
      while (i < n && s[i] == '0') {
        zeroCount++;
        i++;
      }
      // Count consecutive 1's
      int j = i;
      while (j < n && s[j] == '1') {
        oneCount++;
        j++;
      }
      // The balanced substring is min(zeroCount, oneCount) * 2
      maxLen = max(maxLen, min(zeroCount, oneCount) * 2);
      i = j;
    }
    return maxLen;
  }
};
// @lc code=end
