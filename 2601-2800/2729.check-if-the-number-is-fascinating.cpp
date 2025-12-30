/*
 * @lc app=leetcode id=2729 lang=cpp
 *
 * [2729] Check if The Number is Fascinating
 */

// @lc code=start
class Solution {
public:
  bool isFascinating(int n) {
    string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
    if (s.length() != 9)
      return false;
    vector<int> count(10, 0);
    for (char c : s) {
      if (c == '0')
        return false;
      count[c - '0']++;
      if (count[c - '0'] > 1)
        return false;
    }
    return true;
  }
};
// @lc code=end
