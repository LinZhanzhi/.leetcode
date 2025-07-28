/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution {
public:
  int getLucky(string s, int k) {
    // Convert s to a string of digits representing alphabet positions
    string numStr;
    for (char c : s) {
      int val = c - 'a' + 1;
      numStr += to_string(val);
    }
    // Perform k times: sum the digits
    int result = 0;
    for (int i = 0; i < k; ++i) {
      result = 0;
      for (char d : numStr) {
        result += d - '0';
      }
      numStr = to_string(result);
    }
    return result;
  }
};
// @lc code=end
