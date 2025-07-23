/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string copyDouble = s + s; // Copy the string twice
    string delChar = copyDouble.substr(
        1, copyDouble.size() - 2); // Remove first and last character
    return delChar.find(s) !=
           string::npos; // Check if s exists in the modified string
  }
};
// @lc code=end
