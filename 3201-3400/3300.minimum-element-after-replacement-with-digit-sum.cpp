/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
class Solution {
public:
  int minElement(vector<int> &nums) {
    auto digitSum = [](int n) {
      int sum = 0;
      while (n) {
        sum += n % 10;
        n /= 10;
      }
      return sum;
    };
    int res = INT_MAX;
    for (int n : nums) {
      res = min(res, digitSum(n));
    }
    return res;
  }
};
// @lc code=end
