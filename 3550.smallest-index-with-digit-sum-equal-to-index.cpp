/*
 * @lc app=leetcode id=3550 lang=cpp
 *
 * [3550] Smallest Index With Digit Sum Equal to Index
 */

// @lc code=start
class Solution {
public:
  int smallestIndex(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int n = nums[i], sum = 0;
      while (n > 0) {
        sum += n % 10;
        n /= 10;
      }
      if (sum == i)
        return i;
    }
    return -1;
  }
};
// @lc code=end
