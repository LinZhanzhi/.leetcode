/*
 * @lc app=leetcode id=1974 lang=cpp
 *
 * [1974] Minimum Time to Type Word Using Special Typewriter
 */

// @lc code=start
class Solution {
public:
  int minTimeToType(string word) {
    int totalTime = 0;
    char curr = 'a';
    for (char c : word) {
      int diff = abs(c - curr);
      int moveTime = min(diff, 26 - diff);
      totalTime += moveTime + 1; // 1 second to type
      curr = c;
    }
    return totalTime;
  }
};
// @lc code=end
