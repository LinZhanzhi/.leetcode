/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int first = 0, second = 0;
    for (int n : nums) {
      if (n > first) {
        second = first;
        first = n;
      } else if (n > second) {
        second = n;
      }
    }
    return (first - 1) * (second - 1);
  }
};
// @lc code=end
