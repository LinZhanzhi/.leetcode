/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int maxCount = 0, count = 0;
    for (int n : nums) {
      if (n == 1) {
        count++;
        if (count > maxCount)
          maxCount = count;
      } else {
        count = 0;
      }
    }
    return maxCount;
  }
};
// @lc code=end
