/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */

// @lc code=start
class Solution {
public:
  bool isValid(string word) {
    if (word.length() < 3)
      return false;

    bool hasVowel = false, hasConsonant = false;
    for (char c : word) {
      if (!isalnum(c))
        return false; // only digits and letters allowed

      if (isalpha(c)) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' ||
            lower == 'u') {
          hasVowel = true;
        } else {
          hasConsonant = true;
        }
      }
    }
    return hasVowel && hasConsonant;
  }
};
// @lc code=end
