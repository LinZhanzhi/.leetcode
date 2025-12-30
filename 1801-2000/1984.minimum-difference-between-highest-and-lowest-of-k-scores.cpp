/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= nums.size() - k; ++i) {
      int diff = nums[i + k - 1] - nums[i];
      if (diff < min_diff) {
        min_diff = diff;
      }
    }
    return min_diff;
  }
};
// @lc code=end
