/*
 * @lc app=leetcode id=2586 lang=cpp
 *
 * [2586] Count the Number of Vowel Strings in Range
 */

// @lc code=start
class Solution {
public:
  int vowelStrings(vector<string> &words, int left, int right) {
    int count = 0;
    auto isVowel = [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    for (int i = left; i <= right; ++i) {
      const string &word = words[i];
      if (isVowel(word.front()) && isVowel(word.back())) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
