/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int ops = 0;
    for (int x : nums) {
      int rem = x % 3;
      if (rem == 1)
        ops += 1;
      else if (rem == 2)
        ops += 1;
      // if rem == 0, do nothing
    }
    return ops;
  }
};
// @lc code=end
