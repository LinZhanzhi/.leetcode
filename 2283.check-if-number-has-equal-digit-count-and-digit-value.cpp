/*
 * @lc app=leetcode id=2283 lang=cpp
 *
 * [2283] Check if Number Has Equal Digit Count and Digit Value
 */

// @lc code=start
class Solution {
public:
  bool digitCount(string num) {
    // INSERT_YOUR_CODE
    int n = num.size();
    vector<int> count(10, 0);
    for (char c : num) {
      count[c - '0']++;
    }
    for (int i = 0; i < n; ++i) {
      if (count[i] != num[i] - '0') {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
