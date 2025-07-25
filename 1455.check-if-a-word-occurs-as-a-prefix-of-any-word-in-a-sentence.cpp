/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    size_t pos = 0;
    int idx = 1;
    while (true) {
      // Find the next occurrence of searchWord
      size_t found = sentence.find(searchWord, pos);
      if (found == string::npos)
        break;
      // Check if found position is at the start of a word
      if ((found == 0 || sentence[found - 1] == ' ')) {
        // Now, make sure searchWord is at the start of a word (not in the
        // middle)
        return idx + count(sentence.begin(), sentence.begin() + found, ' ');
      }
      pos = found + 1;
    }
    return -1;
  }
};
// @lc code=end
