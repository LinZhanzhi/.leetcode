/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num < 1)
      return false;
    long left = 1, right = num;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long sq = mid * mid;
      if (sq == num)
        return true;
      else if (sq < num)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return false;
  }
};
// @lc code=end
