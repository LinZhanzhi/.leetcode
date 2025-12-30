/*
 * @lc app=leetcode id=2716 lang=cpp
 *
 * [2716] Minimize String Length
 */

// @lc code=start
class Solution {
public:
  int minimizedStringLength(string s) {
    // The minimum length is the number of unique characters in s,
    // since all duplicates can be removed by the allowed operations.
    unordered_set<char> unique_chars(s.begin(), s.end());
    return unique_chars.size();
  }
};
// @lc code=end
