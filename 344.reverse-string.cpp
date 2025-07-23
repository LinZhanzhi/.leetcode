/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  void reverseString(vector<char> &s) {
    for (size_t i = 0, n = s.size(); i < n / 2; ++i) {
      char tmp = s[i];
      s[i] = s[n - 1 - i];
      s[n - 1 - i] = tmp;
    }
  }
};
// @lc code=end
