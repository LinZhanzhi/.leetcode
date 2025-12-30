/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    while (j < typed.size()) {
      // if the current character in name is the same as the current character
      // in typed, move both pointers forward
      if (i < name.size() && name[i] == typed[j]) {
        i++;
        j++;
      }
      // if the current character in typed is the same as the previous character
      // in typed, move the pointer forward
      else if (j > 0 && typed[j] == typed[j - 1]) {
        j++;
      }
      // if the current character in typed is not the same as the current
      // character in name, return false
    }
    else {
      return false;
    }
  }
  return i == name.size();
}
}
;
// @lc code=end
