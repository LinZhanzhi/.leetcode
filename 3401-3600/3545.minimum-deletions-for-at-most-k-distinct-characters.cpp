/*
 * @lc app=leetcode id=3545 lang=cpp
 *
 * [3545] Minimum Deletions for At Most K Distinct Characters
 */

// @lc code=start
class Solution {
public:
  int minDeletion(string s, int k) {
    unordered_map<char, int> freq;
    for (char c : s) {
      freq[c]++;
    }
    if (freq.size() <= k)
      return 0;
    vector<int> counts;
    for (auto &p : freq) {
      counts.push_back(p.second);
    }
    sort(counts.begin(), counts.end());
    int deletions = 0;
    int to_delete = counts.size() - k;
    for (int i = 0; i < to_delete; ++i) {
      deletions += counts[i];
    }
    return deletions;
  }
};
// @lc code=end
