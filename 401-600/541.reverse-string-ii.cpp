/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
  string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
      int left = i;
      int right = min(i + k - 1, n - 1);
      while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
      }
    }
    return s;
  }
};
// @lc code=end
