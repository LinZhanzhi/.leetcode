/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    // Use a dp array to store the maximum amount robbed up to each house.
    // The recurrence relation is:
    //   dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    // This means: for house i, you can either
    //   - skip robbing house i and take the maximum up to house i-1 (dp[i-1]),
    //   or
    //   - rob house i, in which case you must skip house i-1, so you add
    //   nums[i] to the maximum up to house i-2 (dp[i-2] + nums[i]).
    // dp[i] thus represents the maximum money that can be robbed from house 0
    // to house i.
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    // The answer is the max money robbed up to the last house
    return dp[n - 1];
  }
};
// @lc code=end
