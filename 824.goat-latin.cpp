/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
public:
  string toGoatLatin(string sentence) {
    vector<string> words;
    string word, res;
    istringstream iss(sentence);
    while (iss >> word) {
      words.push_back(word);
    }
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < words.size(); ++i) {
      string w = words[i];
      if (vowels.find(w[0]) != string::npos) {
        w += "ma";
      } else {
        w = w.substr(1) + w[0] + "ma";
      }
      w += string(i + 1, 'a');
      if (i > 0)
        res += " ";
      res += w;
    }
    return res;
  }
};
// @lc code=end
