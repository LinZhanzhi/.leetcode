/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_set<string> banned_set(banned.begin(), banned.end());
    unordered_map<string, int> count;
    int n = paragraph.size();
    string word;
    for (int i = 0; i <= n; ++i) {
      char c = (i < n) ? paragraph[i] : ' ';
      if (isalpha(c)) {
        word += tolower(c);
      } else if (!word.empty()) {
        if (banned_set.find(word) == banned_set.end()) {
          count[word]++;
        }
        word.clear();
      }
    }
    string res;
    int max_count = 0;
    for (const auto &p : count) {
      if (p.second > max_count) {
        max_count = p.second;
        res = p.first;
      }
    }
    return res;
  }
};
// @lc code=end
