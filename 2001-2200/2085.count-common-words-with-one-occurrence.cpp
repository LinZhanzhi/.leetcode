/*
 * @lc app=leetcode id=2085 lang=cpp
 *
 * [2085] Count Common Words With One Occurrence
 */

// @lc code=start
class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> count1, count2;
    for (const string &w : words1) {
      count1[w]++;
    }
    for (const string &w : words2) {
      count2[w]++;
    }
    int res = 0;
    for (const auto &[word, cnt] : count1) {
      if (cnt == 1 && count2[word] == 1) {
        res++;
      }
    }
    return res;
  }
};
// @lc code=end
