/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int totalDrank = numBottles;
    int empty = numBottles;
    while (empty >= numExchange) {
      int newBottles = empty / numExchange;
      totalDrank += newBottles;
      empty = empty % numExchange + newBottles;
    }
    return totalDrank;
  }
};
// @lc code=end
