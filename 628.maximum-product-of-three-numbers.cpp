/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    // To get the maximum product of three numbers, we need to consider:
    // 1. The product of the three largest numbers.
    // 2. The product of the two smallest (possibly negative) numbers and the
    // largest number.
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int prod1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int prod2 = nums[0] * nums[1] * nums[n - 1];
    return max(prod1, prod2);
  }
};
// @lc code=end
