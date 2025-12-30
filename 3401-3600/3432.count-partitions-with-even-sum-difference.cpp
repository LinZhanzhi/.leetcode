/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int n = nums.size();
    int total = 0;
    for (int x : nums)
      total += x;
    int left = 0, ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      left += nums[i];
      int right = total - left;
      if ((left - right) % 2 == 0)
        ++ans;
    }
    return ans;
  }
};
// @lc code=end
