/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
class Solution {
public:
  string sortSentence(string s) {
    vector<string> words(9); // Since max 9 words, index 0 unused
    int n = s.size();
    int i = 0;
    int word_count = 0;
    while (i < n) {
      string word = "";
      // Build the word until we hit a digit
      while (i < n && !isdigit(s[i])) {
        word += s[i];
        i++;
      }
      // Now s[i] is a digit (the position)
      int pos = s[i] - '0';
      i++; // move past the digit
      words[pos - 1] = word;
      word_count++;
      // Skip the space if any
      if (i < n && s[i] == ' ')
        i++;
    }
    // Build the result
    string res = "";
    for (int j = 0; j < word_count; ++j) {
      if (j > 0)
        res += " ";
      res += words[j];
    }
    return res;
  }
};
// @lc code=end
