/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    // INSERT_YOUR_CODE
    int n = nums.size();
    int total = 0;
    int subsetCount = 1 << n; // 2^n subsets
    for (int mask = 0; mask < subsetCount; ++mask) {
      int xorSum = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          xorSum ^= nums[i];
        }
      }
      total += xorSum;
    }
    return total;
  }
};
// @lc code=end
