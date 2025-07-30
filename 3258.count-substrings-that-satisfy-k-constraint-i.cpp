/*
 * @lc app=leetcode id=3258 lang=cpp
 *
 * [3258] Count Substrings That Satisfy K-Constraint I
 */

// @lc code=start
class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int cnt0 = 0, cnt1 = 0;
      for (int j = i; j < n; ++j) {
        if (s[j] == '0')
          cnt0++;
        else
          cnt1++;
        if (cnt0 <= k || cnt1 <= k) {
          res++;
        } else {
          // Once both counts exceed k, no longer valid for longer substrings
          break;
        }
      }
    }
    return res;
  }
};
// @lc code=end
