/*
 * @lc app=leetcode id=2833 lang=cpp
 *
 * [2833] Furthest Point From Origin
 */

// @lc code=start
class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int left = 0, right = 0, underscore = 0;
    for (char c : moves) {
      if (c == 'L')
        left++;
      else if (c == 'R')
        right++;
      else
        underscore++;
    }
    // The furthest distance is achieved by assigning all '_' to either L or R
    // So, max(abs((left + underscore) - right), abs((right + underscore) -
    // left)) But since we start at 0, the furthest is just abs(left - right) +
    // underscore
    return abs(left - right) + underscore;
  }
};
// @lc code=end
