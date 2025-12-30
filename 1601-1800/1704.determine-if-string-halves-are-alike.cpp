/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
  bool halvesAreAlike(string s) {
    auto isVowel = [](char c) {
      c = tolower(c);
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int n = s.length();
    int countA = 0, countB = 0;
    for (int i = 0; i < n / 2; ++i) {
      if (isVowel(s[i]))
        countA++;
      if (isVowel(s[i + n / 2]))
        countB++;
    }
    return countA == countB;
  }
};
// @lc code=end
