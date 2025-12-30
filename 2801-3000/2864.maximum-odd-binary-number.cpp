/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 */

// @lc code=start
class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int ones = 0, zeros = 0;
    for (char c : s) {
      if (c == '1')
        ones++;
      else
        zeros++;
    }
    // To make the maximum odd binary number:
    // - Place (ones-1) '1's at the front,
    // - then all zeros,
    // - then one '1' at the end to ensure the number is odd.
    string res(ones - 1, '1');
    res += string(zeros, '0');
    res += '1';
    return res;
  }
};
// @lc code=end
