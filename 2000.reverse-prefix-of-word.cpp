/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
class Solution {
public:
  string reversePrefix(string word, char ch) {
    int idx = word.find(ch);
    if (idx == string::npos) {
      return word;
    }
    reverse(word.begin(), word.begin() + idx + 1);
    return word;
  }
};
// @lc code=end
