/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */

// @lc code=start
class Solution {
public:
  string reorderSpaces(string text) {
    // INSERT_YOUR_CODE
    int spaceCount = 0;
    vector<string> words;
    int n = text.size();
    int i = 0;
    // Count spaces and extract words
    while (i < n) {
      if (text[i] == ' ') {
        spaceCount++;
        i++;
      } else {
        int j = i;
        while (j < n && text[j] != ' ')
          j++;
        words.push_back(text.substr(i, j - i));
        i = j;
      }
    }
    int numWords = words.size();
    string result;
    if (numWords == 1) {
      // All spaces go to the end
      result = words[0] + string(spaceCount, ' ');
    } else {
      int spacesBetween = spaceCount / (numWords - 1);
      int extraSpaces = spaceCount % (numWords - 1);
      for (int k = 0; k < numWords; ++k) {
        result += words[k];
        if (k != numWords - 1) {
          result += string(spacesBetween, ' ');
        }
      }
      result += string(extraSpaces, ' ');
    }
    return result;
  }
};
// @lc code=end
