/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
  bool makeEqual(vector<string> &words) {
    vector<int> freq(26, 0);
    int n = words.size();
    for (const string &word : words) {
      for (char c : word) {
        freq[c - 'a']++;
      }
    }
    for (int count : freq) {
      if (count % n != 0)
        return false;
    }
    return true;
  }
};
// @lc code=end
