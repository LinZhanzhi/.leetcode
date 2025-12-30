/*
 * @lc app=leetcode id=2129 lang=cpp
 *
 * [2129] Capitalize the Title
 */

#include <cctype>
#include <sstream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string capitalizeTitle(string title) {
    stringstream ss(title);
    string word, res;
    while (ss >> word) {
      res += (res.empty() ? "" : " ") + formatWord(word);
    }
    return res;
  }

private:
  string formatWord(string word) {
    if (word.length() <= 2) {
      for (char &c : word)
        c = tolower(c);
    } else {
      word[0] = tolower(word[0]);
      for (int i = 1; i < word.length(); ++i)
        word[i] = tolower(word[i]);
      word[0] = toupper(word[0]);
    }
    return word;
  }
};
// @lc code=end
