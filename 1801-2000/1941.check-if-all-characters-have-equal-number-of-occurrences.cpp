/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
class Solution {
public:
  bool areOccurrencesEqual(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }
    int count = 0;
    for (int f : freq) {
      if (f > 0) {
        if (count == 0)
          count = f;
        else if (f != count)
          return false;
      }
    }
    return true;
  }
};
// @lc code=end
