/*
 * @lc app=leetcode id=2068 lang=cpp
 *
 * [2068] Check Whether Two Strings are Almost Equivalent
 */

// @lc code=start
class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    int freq1[26] = {0}, freq2[26] = {0};
    for (char c : word1)
      freq1[c - 'a']++;
    for (char c : word2)
      freq2[c - 'a']++;
    for (int i = 0; i < 26; ++i) {
      if (abs(freq1[i] - freq2[i]) > 3)
        return false;
    }
    return true;
  }
};
// @lc code=end
