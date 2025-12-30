/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

/*
 * Brief Problem Understanding:
 * ---------------------------
 * We are given a list of houses arranged in a circle, each with some amount of
 * money. We want to rob houses such that we never rob two adjacent houses
 * (because of security alarms). The twist is that the first and last houses are
 * also adjacent (because of the circle). Our goal is to find the maximum amount
 * of money we can rob without ever robbing two adjacent houses.
 */

/*
 * High-Level Solution Summary:
 * ---------------------------
 * The classic "House Robber" problem (linear street) can be solved with dynamic
 * programming (DP). However, because the houses are in a circle, we cannot rob
 * both the first and last house. To handle this, we split the problem into two
 * cases:
 *   1. Rob houses from the first to the second-to-last (exclude the last
 * house).
 *   2. Rob houses from the second to the last (exclude the first house).
 * For each case, we use the standard DP approach for the linear version of the
 * problem. The answer is the maximum of these two cases.
 *
 * Time Complexity: O(N), where N is the number of houses.
 * Space Complexity: O(1), since we only need a few variables for DP (not the
 * whole array).
 */

#include <algorithm> // Include algorithm for std::max
#include <vector>    // Include vector for using std::vector

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
  // Helper function to solve the linear House Robber problem for a subarray
  int robLinear(const vector<int> &nums, int start, int end) {
    // Initialize two variables to keep track of the maximum money robbed so
    // far: prev1: max money if we rob up to the previous house prev2: max money
    // if we rob up to the house before the previous
    int prev1 = 0; // dp[i-1]
    int prev2 = 0; // dp[i-2]
    for (int i = start; i <= end; ++i) {
      // For each house, decide to rob it (add nums[i] to prev2) or skip it
      // (keep prev1)
      int curr = max(prev1, prev2 + nums[i]);
      // Update prev2 and prev1 for the next iteration
      prev2 = prev1;
      prev1 = curr;
    }
    // prev1 now contains the maximum money that can be robbed in this range
    return prev1;
  }

  int rob(vector<int> &nums) {
    int n = nums.size();
    // Edge case: If there are no houses, return 0
    if (n == 0)
      return 0;
    // Edge case: If there is only one house, rob it
    if (n == 1)
      return nums[0];
    // Edge case: If there are two houses, rob the one with more money
    if (n == 2)
      return max(nums[0], nums[1]);
    // Case 1: Exclude the last house (rob from 0 to n-2)
    int case1 = robLinear(nums, 0, n - 2);
    // Case 2: Exclude the first house (rob from 1 to n-1)
    int case2 = robLinear(nums, 1, n - 1);
    // The answer is the maximum of the two cases
    return max(case1, case2);
  }
};
// @lc code=end
