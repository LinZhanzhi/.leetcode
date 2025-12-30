/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <sstream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;
    int n = s.size();
    int i = 0;
    while (i < n) {
      // Skip spaces
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
    string result;
    for (int k = words.size() - 1; k >= 0; --k) {
      result += words[k];
      if (k != 0)
        result += ' ';
    }
    return result;
  }
};
// @lc code=end
