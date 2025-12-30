/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;
    int skipS = 0, skipT = 0;
    while (i >= 0 || j >= 0) {
      // Find next valid char in s
      while (i >= 0) {
        // if current char is '#', skip it
        if (s[i] == '#') {
          skipS++;
          i--;
        }
        // if current char is not '#' and skipS is greater than 0, skip it
        else if (skipS > 0) {
          skipS--;
          i--;
        } else {
          break;
        }
      }
      // Find next valid char in t
      while (j >= 0) {
        // if current char is '#', skip it
        if (t[j] == '#') {
          skipT++;
          j--;
        }
        // if current char is not '#' and skipT is greater than 0, skip it
        else if (skipT > 0) {
          skipT--;
          j--;
        } else {
          break;
        }
      }
      // Compare characters
      if (i >= 0 && j >= 0 && s[i] != t[j])
        return false;
      // if one of the strings is not fully processed, return false
      if ((i >= 0) != (j >= 0))
        return false;
      i--;
      j--;
    }
    return true;
  }
};
// @lc code=end
