/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
  int maxScore(string s) {
    int totalOnes = 0;
    for (char c : s) {
      if (c == '1')
        totalOnes++;
    }
    int maxScore = 0;
    int leftZeros = 0, rightOnes = totalOnes;
    // We split at position i (left: s[0..i], right: s[i+1..n-1]), so i from 0
    // to n-2
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == '0')
        leftZeros++;
      else
        rightOnes--;
      int score = leftZeros + rightOnes;
      if (score > maxScore)
        maxScore = score;
    }
    return maxScore;
  }
};
// @lc code=end
