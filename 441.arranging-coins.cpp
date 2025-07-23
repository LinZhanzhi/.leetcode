/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
  int arrangeCoins(int n) {
    // INSERT_YOUR_CODE
    // We need to find the largest k such that k*(k+1)/2 <= n
    long left = 0, right = n;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long curr = mid * (mid + 1) / 2;
      if (curr == n) {
        return (int)mid;
      } else if (curr < n) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return (int)right;
  }
};
// @lc code=end
