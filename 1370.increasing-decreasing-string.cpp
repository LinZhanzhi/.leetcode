/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */

// @lc code=start
class Solution {
public:
  string sortString(string s) {
    vector<int> count(26, 0);
    for (char c : s) {
      count[c - 'a']++;
    }
    string res;
    int n = s.size();
    while (res.size() < n) {
      // Step 1-3: increasing order
      for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
          res += ('a' + i);
          count[i]--;
        }
      }
      // Step 4-6: decreasing order
      for (int i = 25; i >= 0; --i) {
        if (count[i] > 0) {
          res += ('a' + i);
          count[i]--;
        }
      }
    }
    return res;
  }
};
// @lc code=end
