/*
 * @lc app=leetcode id=2744 lang=cpp
 *
 * [2744] Find Maximum Number of String Pairs
 */

// @lc code=start
class Solution {
public:
  int maximumNumberOfStringPairs(vector<string> &words) {
    int n = words.size();
    int count = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
      if (used[i])
        continue;
      string rev = words[i];
      reverse(rev.begin(), rev.end());
      for (int j = i + 1; j < n; ++j) {
        if (!used[j] && words[j] == rev) {
          count++;
          used[i] = true;
          used[j] = true;
          break;
        }
      }
    }
    return count;
  }
};
// @lc code=end
