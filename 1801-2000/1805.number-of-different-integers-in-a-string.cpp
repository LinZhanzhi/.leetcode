/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */

// @lc code=start
class Solution {
public:
  int numDifferentIntegers(string word) {
    unordered_set<string> nums;
    int n = word.size();
    int i = 0;
    while (i < n) {
      // Skip non-digit characters
      if (!isdigit(word[i])) {
        ++i;
        continue;
      }
      // Start of a number
      int j = i;
      while (j < n && isdigit(word[j]))
        ++j;
      // Remove leading zeros
      int k = i;
      while (k < j && word[k] == '0')
        ++k;
      string num = (k == j) ? "0" : word.substr(k, j - k);
      nums.insert(num);
      i = j;
    }
    return nums.size();
  }
};
// @lc code=end
