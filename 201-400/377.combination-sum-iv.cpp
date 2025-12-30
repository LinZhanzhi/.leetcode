/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of unique positive integers (`nums`) and a target sum
 * (`target`). The task is to count how many different ordered combinations of
 * numbers from `nums` can sum up to exactly `target`. Each number in `nums` can
 * be used any number of times, and the order of numbers in the combination
 * matters (so [1,2,1] and [1,1,2] are different).
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses dynamic programming (DP) to efficiently count the number of
 * possible ordered combinations. We define a DP array `dp` where `dp[i]`
 * represents the number of ways to reach the sum `i` using the numbers in
 * `nums`. We initialize `dp[0] = 1` (one way to make sum 0: use nothing). For
 * each sum from 1 to `target`, we iterate through all numbers in `nums` and, if
 * the number can contribute to the current sum, we add the number of ways to
 * make the remaining sum (`i - num`) to `dp[i]`. This approach ensures that all
 * possible orderings are counted.
 *
 * Time Complexity: O(target * n), where n is the size of `nums`.
 * Space Complexity: O(target), for the DP array.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    // Create a DP array of size (target + 1), initialized to 0.
    // dp[i] will store the number of combinations to reach sum i.
    vector<unsigned int> dp(target + 1, 0);

    // Base case: There is 1 way to make sum 0 (by choosing nothing).
    dp[0] = 1;

    // Iterate through all possible sums from 1 to target.
    for (int i = 1; i <= target; ++i) {
      // For each number in nums, check if it can contribute to the current sum.
      for (int num : nums) {
        if (i - num >= 0) {
          // If num can be used, add the number of ways to make (i - num) to
          // dp[i]. This counts all combinations ending with 'num' that sum to
          // i.
          dp[i] += dp[i - num];
        }
        // If num > i, it cannot be used for this sum, so we skip it.
      }
    }

    // The answer is the number of ways to make the target sum.
    return dp[target];
  }
};
// @lc code=end
