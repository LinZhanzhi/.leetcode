/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start
class Solution {
public:
  bool isCircularSentence(string sentence) {
    int n = sentence.size();
    // Find the first character of the first word
    char firstChar = sentence[0];
    // Find the last character of the last word
    char lastChar = sentence[n - 1];
    // Check circularity between last and first word
    if (firstChar != lastChar)
      return false;
    // Now check between each pair of words
    for (int i = 0; i < n; ++i) {
      if (sentence[i] == ' ') {
        // i is the space, so i-1 is the last char of previous word, i+1 is the
        // first char of next word
        if (sentence[i - 1] != sentence[i + 1])
          return false;
      }
    }
    return true;
  }
};
// @lc code=end
