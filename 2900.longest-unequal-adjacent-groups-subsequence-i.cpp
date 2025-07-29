/*
 * @lc app=leetcode id=2900 lang=cpp
 *
 * [2900] Longest Unequal Adjacent Groups Subsequence I
 */

// @lc code=start
class Solution {
public:
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    vector<string> res;
    int n = words.size();
    int last_group = -1;
    for (int i = 0; i < n; ++i) {
      if (res.empty() || groups[i] != last_group) {
        res.push_back(words[i]);
        last_group = groups[i];
      }
    }
    return res;
  }
};
// @lc code=end
