/*
 * @lc app=leetcode id=3042 lang=cpp
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
class Solution {
public:
  int countPrefixSuffixPairs(vector<string> &words) {
    int n = words.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const string &str1 = words[i];
        const string &str2 = words[j];
        int len1 = str1.size();
        int len2 = str2.size();
        if (len1 > len2)
          continue;
        // Check prefix
        bool isPrefix = str2.substr(0, len1) == str1;
        // Check suffix
        bool isSuffix = str2.substr(len2 - len1, len1) == str1;
        if (isPrefix && isSuffix) {
          ++count;
        }
      }
    }
    return count;
  }
};
// @lc code=end
