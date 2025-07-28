/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 */

// @lc code=start
class Solution {
public:
  int findMiddleIndex(vector<int> &nums) {
    int total = 0;
    for (int n : nums)
      total += n;
    int leftSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (leftSum == total - leftSum - nums[i])
        return i;
      leftSum += nums[i];
    }
    return -1;
  }
};
// @lc code=end
