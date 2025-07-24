/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
  int binaryGap(int n) {
    int maxGap = 0;
    int lastPos = -1;
    int pos = 0;
    while (n > 0) {
      if (n & 1) {
        if (lastPos != -1) {
          maxGap = std::max(maxGap, pos - lastPos);
        }
        lastPos = pos;
      }
      n >>= 1;
      pos++;
    }
    return maxGap;
  }
};
// @lc code=end
