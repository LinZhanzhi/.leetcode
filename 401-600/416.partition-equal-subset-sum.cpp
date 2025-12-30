/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to determine if a given array of positive integers can be split
 * into two subsets whose sums are exactly equal. In other words, can we divide
 * the array into two groups so that the sum of numbers in each group is the
 * same? This is a classic "subset sum" problem, where we want to know if there
 * exists a subset of the array that sums up to half of the total sum.
 *
 * High-Level Summary:
 * ----
 * The solution first checks if the total sum of the array is even; if not, it's
 * impossible to split it into two equal parts. If the sum is even, we use
 * dynamic programming to check if there is a subset of the array that sums up
 * to half of the total sum. We use a 1D boolean DP array where dp[i] means "is
 * it possible to get a sum of i using some subset of the numbers seen so far?"
 * We iterate through the numbers and update the DP array accordingly. The time
 * complexity is O(n * target), where n is the number of elements and target is
 * half the total sum. The space complexity is O(target).
 */

#include <numeric> // Include numeric for std::accumulate
#include <vector>  // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    // Calculate the total sum of all elements in the array
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

    // If the total sum is odd, it's impossible to split into two equal subsets
    if (totalSum % 2 != 0) {
      return false;
    }

    // The target sum for each subset is half of the total sum
    int target = totalSum / 2;

    // Create a DP array where dp[i] is true if a subset sum of i is possible
    // Initialize dp[0] = true because a sum of 0 is always possible (empty
    // subset)
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    // Iterate through each number in the input array
    for (int num : nums) {
      // Traverse dp array backwards to avoid using the same number multiple
      // times
      for (int i = target; i >= num; --i) {
        // If a subset sum of (i - num) is possible, then a subset sum of i is
        // also possible
        if (dp[i - num]) {
          dp[i] = true;
        }
      }
    }

    // The answer is whether a subset sum of 'target' is possible
    return dp[target];
  }
};
// @lc code=end
