/*
 * @lc app=leetcode id=2937 lang=cpp
 *
 * [2937] Make Three Strings Equal
 */

// @lc code=start
class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    // INSERT_YOUR_CODE
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    int minLen = min({n1, n2, n3});
    int common = 0;
    // Find the longest common prefix
    for (int i = 0; i < minLen; ++i) {
      if (s1[i] == s2[i] && s2[i] == s3[i]) {
        ++common;
      } else {
        break;
      }
    }
    // If no common prefix, impossible
    if (common == 0)
      return -1;
    // Otherwise, remove all characters after the common prefix in each string
    return (n1 - common) + (n2 - common) + (n3 - common);
  }
};
// @lc code=end
