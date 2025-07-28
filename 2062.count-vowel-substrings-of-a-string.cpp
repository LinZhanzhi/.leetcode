/*
 * @lc app=leetcode id=2062 lang=cpp
 *
 * [2062] Count Vowel Substrings of a String
 */

// @lc code=start
class Solution {
public:
  int countVowelSubstrings(string word) {
    int n = word.size();
    auto isVowel = [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (!isVowel(word[i]))
        continue;
      int mask = 0;
      for (int j = i; j < n; ++j) {
        if (!isVowel(word[j]))
          break;
        // set bit for each vowel
        if (word[j] == 'a')
          mask |= 1 << 0;
        else if (word[j] == 'e')
          mask |= 1 << 1;
        else if (word[j] == 'i')
          mask |= 1 << 2;
        else if (word[j] == 'o')
          mask |= 1 << 3;
        else if (word[j] == 'u')
          mask |= 1 << 4;
        if (mask == 0b11111)
          res++;
      }
    }
    return res;
  }
};
// @lc code=end
