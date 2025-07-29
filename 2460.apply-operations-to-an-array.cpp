/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    int n = nums.size();
    // Step 1: Apply the operations
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }
    // Step 2: Shift all zeros to the end
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0)
        res.push_back(nums[i]);
    }
    while (res.size() < n)
      res.push_back(0);
    return res;
  }
};
// @lc code=end
