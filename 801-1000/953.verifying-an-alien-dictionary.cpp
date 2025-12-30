/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<int> pos(26);
    for (int i = 0; i < 26; ++i) {
      pos[order[i] - 'a'] = i;
    }
    auto inAlienOrder = [&](const string &a, const string &b) -> bool {
      int n = min(a.size(), b.size());
      for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
          return pos[a[i] - 'a'] < pos[b[i] - 'a'];
        }
      }
      return a.size() <= b.size();
    };
    for (int i = 1; i < words.size(); ++i) {
      if (!inAlienOrder(words[i - 1], words[i])) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
