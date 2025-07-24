/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    // INSERT_YOUR_CODE
    vector<int> plateCount(26, 0);
    for (char c : licensePlate) {
      if (isalpha(c)) {
        plateCount[tolower(c) - 'a']++;
      }
    }
    string res;
    int minLen = INT_MAX;
    for (const string &word : words) {
      vector<int> wordCount(26, 0);
      for (char c : word) {
        wordCount[c - 'a']++;
      }
      bool valid = true;
      for (int i = 0; i < 26; ++i) {
        if (wordCount[i] < plateCount[i]) {
          valid = false;
          break;
        }
      }
      if (valid && word.length() < minLen) {
        minLen = word.length();
        res = word;
      }
    }
    return res;
  }
};
// @lc code=end
