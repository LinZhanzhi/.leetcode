/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int num = left; num <= right; ++num) {
      int n = num;
      bool isSelfDividing = true;
      while (n > 0) {
        int digit = n % 10;
        if (digit == 0 || num % digit != 0) {
          isSelfDividing = false;
          break;
        }
        n /= 10;
      }
      if (isSelfDividing) {
        res.push_back(num);
      }
    }
    return res;
  }
};
// @lc code=end
