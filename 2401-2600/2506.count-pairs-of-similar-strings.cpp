/*
 * @lc app=leetcode id=2506 lang=cpp
 *
 * [2506] Count Pairs Of Similar Strings
 */

// @lc code=start
class Solution {
public:
  int similarPairs(vector<string> &words) {
    // INSERT_YOUR_CODE
    int n = words.size();
    vector<int> masks(n, 0);
    for (int i = 0; i < n; ++i) {
      int mask = 0;
      for (char c : words[i]) {
        mask |= (1 << (c - 'a'));
      }
      masks[i] = mask;
    }
    unordered_map<int, int> maskCount;
    for (int mask : masks) {
      ++maskCount[mask];
    }
    int count = 0;
    for (const auto &[mask, freq] : maskCount) {
      count += freq * (freq - 1) / 2;
    }
    return count;
  }
};
// @lc code=end
