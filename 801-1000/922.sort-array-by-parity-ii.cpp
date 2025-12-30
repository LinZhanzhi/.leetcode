/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int n = nums.size();
    int even = 0, odd = 1;
    while (even < n && odd < n) {
      // Find the first misplaced even index
      while (even < n && nums[even] % 2 == 0)
        even += 2;
      // Find the first misplaced odd index
      while (odd < n && nums[odd] % 2 == 1)
        odd += 2;
      // Swap if both are in range
      if (even < n && odd < n) {
        std::swap(nums[even], nums[odd]);
      }
    }
    return nums;
  }
};
// @lc code=end
