/*
 * @lc app=leetcode id=3146 lang=cpp
 *
 * [3146] Permutation Difference between Two Strings
 */

// @lc code=start
class Solution {
public:
  int findPermutationDifference(string s, string t) {
    unordered_map<char, int> idx_s, idx_t;
    for (int i = 0; i < s.size(); ++i) {
      idx_s[s[i]] = i;
      idx_t[t[i]] = i;
    }
    int ans = 0;
    for (auto &[ch, i] : idx_s) {
      ans += abs(i - idx_t[ch]);
    }
    return ans;
  }
};
// @lc code=end
