/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

#include <string>
using std::string;

// @lc code=start
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    string result;
    result.reserve(n1 + n2);
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
      result += word1[i++];
      result += word2[j++];
    }
    while (i < n1)
      result += word1[i++];
    while (j < n2)
      result += word2[j++];
    return result;
  }
};
// @lc code=end
