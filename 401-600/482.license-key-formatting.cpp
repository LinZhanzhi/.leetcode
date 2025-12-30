/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    // Remove all dashes and convert to uppercase
    string cleaned;
    for (char c : s) {
      if (c != '-') {
        cleaned += toupper(c);
      }
    }
    // Early return if empty
    if (cleaned.empty())
      return "";

    string result;
    int firstGroupLen = cleaned.length() % k;
    int i = 0;
    // Add the first group (could be shorter)
    if (firstGroupLen > 0) {
      result += cleaned.substr(0, firstGroupLen);
      i = firstGroupLen;
      if (i < cleaned.length())
        result += '-';
    }
    // Add the rest of the groups
    while (i < cleaned.length()) {
      result += cleaned.substr(i, k);
      i += k;
      if (i < cleaned.length())
        result += '-';
    }
    return result;
  }
};
// @lc code=end
