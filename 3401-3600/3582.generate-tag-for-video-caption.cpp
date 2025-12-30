/*
 * @lc app=leetcode id=3582 lang=cpp
 *
 * [3582] Generate Tag for Video Caption
 */

// @lc code=start
class Solution {
public:
  string generateTag(string caption) {
    // Split the caption into words
    vector<string> words;
    int n = caption.size();
    int i = 0;
    while (i < n) {
      // Skip spaces
      while (i < n && caption[i] == ' ')
        ++i;
      if (i >= n)
        break;
      int j = i;
      while (j < n && caption[j] != ' ')
        ++j;
      words.push_back(caption.substr(i, j - i));
      i = j;
    }

    string tag = "#";
    for (int k = 0; k < words.size(); ++k) {
      string w = words[k];
      if (w.empty())
        continue;
      for (int c = 0; c < w.size(); ++c) {
        if (!isalpha(w[c]))
          continue;
        if (k == 0) {
          // First word: all lowercase
          tag += tolower(w[c]);
        } else {
          if (c == 0) {
            tag += toupper(w[c]);
          } else {
            tag += tolower(w[c]);
          }
        }
      }
    }
    if (tag.size() > 100)
      tag = tag.substr(0, 100);
    return tag;
  }
};
// @lc code=end
