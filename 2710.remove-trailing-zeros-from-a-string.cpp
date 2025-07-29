/*
 * @lc app=leetcode id=2710 lang=cpp
 *
 * [2710] Remove Trailing Zeros From a String
 */

// @lc code=start
class Solution {
public:
  string removeTrailingZeros(string num) {
    // Remove trailing zeros by finding the last non-zero character
    int i = num.size() - 1;
    while (i >= 0 && num[i] == '0') {
      --i;
    }
    return num.substr(0, i + 1);
  }
};
// @lc code=end
