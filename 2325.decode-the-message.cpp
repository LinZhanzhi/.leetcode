/*
 * @lc app=leetcode id=2325 lang=cpp
 *
 * [2325] Decode the Message
 */

// @lc code=start
class Solution {
public:
  string decodeMessage(string key, string message) {
    // Build the substitution table
    char mapping[26] = {0};
    bool seen[26] = {false};
    char curr = 'a';
    for (char c : key) {
      if (c == ' ')
        continue;
      if (!seen[c - 'a']) {
        mapping[c - 'a'] = curr;
        seen[c - 'a'] = true;
        curr++;
      }
    }
    // Decode the message
    string res;
    for (char c : message) {
      if (c == ' ') {
        res += ' ';
      } else {
        res += mapping[c - 'a'];
      }
    }
    return res;
  }
};
// @lc code=end
