/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
  string longestNiceSubstring(string s) {
    int n = s.size();
    int maxLen = 0, startIdx = 0;

    for (int i = 0; i < n; ++i) {
      int lower = 0, upper = 0;
      for (int j = i; j < n; ++j) {
        char c = s[j];
        if (islower(c))
          lower |= (1 << (c - 'a'));
        else if (isupper(c))
          upper |= (1 << (c - 'A'));
        if (lower == upper && (j - i + 1) > maxLen) {
          maxLen = j - i + 1;
          startIdx = i;
        }
      }
    }
    return s.substr(startIdx, maxLen);
  }
};
// @lc code=end
