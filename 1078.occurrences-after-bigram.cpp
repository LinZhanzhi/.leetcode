/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> res;
    vector<string> words;
    int n = text.size();
    int i = 0;
    while (i < n) {
      // Find the start of the next word
      while (i < n && text[i] == ' ')
        ++i;
      if (i >= n)
        break;
      int j = i;
      while (j < n && text[j] != ' ')
        ++j;
      words.push_back(text.substr(i, j - i));
      i = j;
    }
    for (int k = 2; k < words.size(); ++k) {
      if (words[k - 2] == first && words[k - 1] == second) {
        res.push_back(words[k]);
      }
    }
    return res;
  }
};
// @lc code=end
