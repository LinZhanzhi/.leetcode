/*
 * @lc app=leetcode id=2932 lang=cpp
 *
 * [2932] Maximum Strong Pair XOR I
 */

// @lc code=start
class Solution {
public:
  int maximumStrongPairXor(vector<int> &nums) {
    int n = nums.size();
    int maxXor = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int x = nums[i], y = nums[j];
        if (abs(x - y) <= min(x, y)) {
          maxXor = max(maxXor, x ^ y);
        }
      }
    }
    return maxXor;
  }
};
// @lc code=end
