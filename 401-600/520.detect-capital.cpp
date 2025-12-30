/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
  bool detectCapitalUse(string word) {
    // Check if all letters are uppercase
    if (all_of(word.begin(), word.end(), ::isupper))
      return true;
    // Check if all letters are lowercase
    if (all_of(word.begin(), word.end(), ::islower))
      return true;
    // Check if only the first letter is uppercase and the rest are lowercase
    if (isupper(word[0]) && all_of(word.begin() + 1, word.end(), ::islower))
      return true;
    return false;
  }
};
// @lc code=end
