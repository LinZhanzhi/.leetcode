/*
 * @lc app=leetcode id=2176 lang=cpp
 *
 * [2176] Count Equal and Divisible Pairs in an Array
 */

// @lc code=start
class Solution {
public:
  int countPairs(vector<int> &nums, int k) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] == nums[j] && ((i * j) % k == 0)) {
          ++count;
        }
      }
    }
    return count;
  }
};
// @lc code=end
