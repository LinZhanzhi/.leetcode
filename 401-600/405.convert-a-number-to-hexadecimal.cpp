/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
  string toHex(int num) {
    if (num == 0)
      return "0";
    string hex = "";
    unsigned int n = num; // handle negative numbers using two's complement
    char hexChars[] = "0123456789abcdef";
    while (n && hex.length() < 8) {
      hex = hexChars[n & 0xf] + hex;
      n >>= 4;
    }
    return hex;
  }
};
// @lc code=end
