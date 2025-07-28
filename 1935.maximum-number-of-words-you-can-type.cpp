/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    // Use a fixed-size array for broken letters for better memory usage and
    // speed
    bool broken[26] = {false};
    for (char c : brokenLetters) {
      broken[c - 'a'] = true;
    }
    int count = 0;
    int n = text.size();
    int i = 0;
    while (i < n) {
      bool canType = true;
      // Process one word at a time
      while (i < n && text[i] != ' ') {
        if (broken[text[i] - 'a']) {
          canType = false;
        }
        ++i;
      }
      if (canType)
        ++count;
      // Skip the space
      while (i < n && text[i] == ' ')
        ++i;
    }
    return count;
  }
};
// @lc code=end
