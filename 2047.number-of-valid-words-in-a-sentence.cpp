/*
 * @lc app=leetcode id=2047 lang=cpp
 *
 * [2047] Number of Valid Words in a Sentence
 */

#include <cctype>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int countValidWords(string sentence) {
    int res = 0;
    int n = sentence.size();
    int i = 0;
    while (i < n) {
      // Skip spaces
      i = skipSpaces(sentence, i);
      if (i >= n)
        break;
      int j = nextTokenEnd(sentence, i);
      string token = sentence.substr(i, j - i);
      if (isValidToken(token))
        ++res;
      i = j;
    }
    return res;
  }

private:
  /*
   * Skip spaces
   * @param s The sentence
   * @param i The index of the current position
   * @return The index of the next non-space character
   */
  int skipSpaces(const string &s, int i) {
    int n = s.size();
    while (i < n && s[i] == ' ')
      ++i;
    return i;
  }

  /*
   * Find the end of the next token
   * @param s The sentence
   * @param i The index of the current position
   * @return The index of the end of the next token
   */
  int nextTokenEnd(const string &s, int i) {
    int n = s.size();
    while (i < n && s[i] != ' ')
      ++i;
    return i;
  }

  /*
   * Check if a token is valid
   * @param token The token to check
   * @return True if the token is valid, false otherwise
   */
  bool isValidToken(const string &token) {
    int hyphen = 0, punct = 0;
    int len = token.size();
    for (int k = 0; k < len; ++k) {
      char c = token[k];
      if (isdigit(c)) {
        return false;
      }
      if (c == '-') {
        ++hyphen;
        // Hyphen must be surrounded by lowercase letters
        if (hyphen > 1 || k == 0 || k == len - 1 || !islower(token[k - 1]) ||
            !islower(token[k + 1])) {
          return false;
        }
      }
      if (c == '!' || c == '.' || c == ',') {
        ++punct;
        // Punctuation must be at the end
        if (punct > 1 || k != len - 1) {
          return false;
        }
      }
      if (!(islower(c) || c == '-' || c == '!' || c == '.' || c == ',')) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
