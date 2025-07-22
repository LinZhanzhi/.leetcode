/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    // Check if lengths are different
    if (s.length() != t.length()) {
      return false;
    }

    // Use arrays to track mappings (ASCII characters)
    char sToT[128] = {0}; // s -> t mapping
    char tToS[128] = {0}; // t -> s mapping

    for (int i = 0; i < s.length(); i++) {
      char sChar = s[i];
      char tChar = t[i];

      // Check if s[i] is already mapped
      if (sToT[sChar] != 0) {
        // If mapping doesn't match, return false
        if (sToT[sChar] != tChar) {
          return false;
        }
      } else {
        // Check if t[i] is already mapped to a different character
        if (tToS[tChar] != 0) {
          return false;
        }

        // Create new mapping
        sToT[sChar] = tChar;
        tToS[tChar] = sChar;
      }
    }

    return true;
  }
};
// @lc code=end
