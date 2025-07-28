/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

// @lc code=start
class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> boxCount;
    int maxBalls = 0;
    for (int i = lowLimit; i <= highLimit; ++i) {
      int sum = 0, num = i;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      boxCount[sum]++;
      if (boxCount[sum] > maxBalls) {
        maxBalls = boxCount[sum];
      }
    }
    return maxBalls;
  }
};
// @lc code=end
