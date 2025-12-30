/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    // Create a bucket for each of 26 letters
    bool bucket[26] = {false};
    for (char c : allowed) {
      bucket[c - 'a'] = true;
    }
    int count = 0;
    for (const string &word : words) {
      bool consistent = true;
      for (char c : word) {
        if (!bucket[c - 'a']) {
          consistent = false;
          break;
        }
      }
      if (consistent)
        ++count;
    }
    return count;
  }
};
// @lc code=end
