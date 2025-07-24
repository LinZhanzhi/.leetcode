/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
      freq[num]++;
    }
    unordered_set<int> seen;
    for (const auto &p : freq) {
      if (seen.count(p.second)) {
        return false;
      }
      seen.insert(p.second);
    }
    return true;
  }
};
// @lc code=end
