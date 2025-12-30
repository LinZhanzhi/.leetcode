/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int count = 0;
    for (int num : nums) {
      int digits = 0;
      int n = num;
      while (n > 0) {
        digits++;
        n /= 10;
      }
      if (digits % 2 == 0) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
