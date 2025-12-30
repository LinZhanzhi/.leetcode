/*
 * @lc app=leetcode id=2269 lang=cpp
 *
 * [2269] Find the K-Beauty of a Number
 */

// @lc code=start
class Solution {
public:
  int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int n = s.size();
    int count = 0;
    for (int i = 0; i <= n - k; ++i) {
      string sub = s.substr(i, k);
      int val = stoi(sub);
      if (val != 0 && num % val == 0) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
