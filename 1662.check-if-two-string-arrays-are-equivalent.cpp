/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    string s1, s2;
    for (const auto &w : word1)
      s1 += w;
    for (const auto &w : word2)
      s2 += w;
    return s1 == s2;
  }
};
// @lc code=end
