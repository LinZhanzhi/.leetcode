/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    vector<int> chars_count(26, 0);
    for (char c : chars) {
      chars_count[c - 'a']++;
    }
    int total = 0;
    for (const string &word : words) {
      vector<int> word_count(26, 0);
      for (char c : word) {
        word_count[c - 'a']++;
      }
      bool can_form = true;
      for (int i = 0; i < 26; ++i) {
        if (word_count[i] > chars_count[i]) {
          can_form = false;
          break;
        }
      }
      if (can_form) {
        total += word.size();
      }
    }
    return total;
  }
};
// @lc code=end
