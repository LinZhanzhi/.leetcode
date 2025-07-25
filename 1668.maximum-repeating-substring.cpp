/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

// @lc code=start
class Solution {
public:
  int maxRepeating(string sequence, string word) {
    int maxK = 0;
    int n = sequence.size(), m = word.size();
    for (int k = 1;; ++k) {
      string repeated = "";
      for (int i = 0; i < k; ++i)
        repeated += word;
      if (sequence.find(repeated) != string::npos) {
        maxK = k;
      } else {
        break;
      }
    }
    return maxK;
  }
};
// @lc code=end
