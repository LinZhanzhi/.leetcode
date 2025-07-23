/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<string> words;
    int n = s.size(), i = 0;
    while (i < n) {
      while (i < n && s[i] == ' ')
        ++i;
      if (i >= n)
        break;
      int j = i;
      while (j < n && s[j] != ' ')
        ++j;
      words.push_back(s.substr(i, j - i));
      i = j;
    }

    if (pattern.length() != words.size()) {
      return false;
    }

    unordered_map<char, string> p2w;
    unordered_map<string, char> w2p;

    for (int i = 0; i < pattern.length(); ++i) {
      char c = pattern[i];
      const string &w = words[i];
      if (p2w.count(c)) {
        if (p2w[c] != w)
          return false;
      } else {
        if (w2p.count(w))
          return false;
        p2w[c] = w;
        w2p[w] = c;
      }
    }
    return true;
  }
};
// @lc code=end
