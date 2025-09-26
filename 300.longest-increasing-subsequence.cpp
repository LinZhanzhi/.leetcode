/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given an array of integers and need to find the length of the longest
 * subsequence where each number is strictly greater than the previous one. A
 * subsequence can skip elements, but must keep the original order. The
 * challenge is to do this efficiently, especially for large arrays.
 *
 * There are two classic approaches: a straightforward dynamic programming (DP)
 * solution, and a more efficient greedy + binary search solution. The code
 * below uses the latter, but we'll also explain the DP approach for clarity.
 */

/*
 * High-Level Summary:
 * ----
 * Greedy + Binary Search Approach (O(n log n)):
 *   - We maintain a list called 'tails', where tails[i] is the smallest
 * possible tail value of an increasing subsequence of length i+1 found so far.
 *   - For each number in the input, we use binary search to find its position
 * in 'tails':
 *     - If the number is larger than all tails, it extends the largest
 * subsequence.
 *     - Otherwise, it replaces the first tail that is greater than or equal to
 * it, keeping tails as small as possible for future extension.
 *   - The length of 'tails' at the end is the answer.
 *
 *   - This is not a classic DP in the sense of filling a dp[] table with
 * subproblem answers, but it can be seen as an optimization over the O(n^2) DP
 * approach.
 *
 * Classic DP Approach (O(n^2)), for illustration:
 *   - Let dp[i] be the length of the longest increasing subsequence ending at
 * index i.
 *   - For each i, look at all j < i, and if nums[j] < nums[i], set dp[i] =
 * max(dp[i], dp[j] + 1).
 *   - The answer is max(dp[i]) for all i.
 *
 * Time Complexity: O(n log n) for the greedy + binary search approach.
 * Space Complexity: O(n), for the 'tails' array.
 */

#include <algorithm> // Include algorithm for std::lower_bound
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // This function returns the length of the longest increasing subsequence in
  // nums.
  int lengthOfLIS(vector<int> &nums) {
    // 'tails' will store the smallest tail of all increasing subsequences
    // with different lengths found so far.
    vector<int> tails;

    // Iterate through each number in the input array.
    for (int num : nums) {
      // Use binary search to find the first element in 'tails' which is
      // greater than or equal to 'num'. This is where 'num' can extend or
      // replace an existing subsequence.
      auto it = std::lower_bound(tails.begin(), tails.end(), num);

      if (it == tails.end()) {
        // If 'num' is greater than all elements in 'tails', it extends the
        // largest subsequence found so far. So, we append it.
        tails.push_back(num);
      } else {
        // Otherwise, replace the first element in 'tails' which is >= 'num'
        // with 'num'. This keeps 'tails' as small as possible, which is
        // crucial for future numbers to build longer increasing subsequences.
        *it = num;
      }
      // At every step, 'tails' is sorted and its length is the length of the
      // longest increasing subsequence found so far.
    }

    // The size of 'tails' is the answer: the length of the longest increasing
    // subsequence.
    return static_cast<int>(tails.size());
  }

  /*
   * (For educational purposes) Classic DP approach, O(n^2) time:
   * Uncomment to use this version instead.
   *
   * int lengthOfLIS(vector<int> &nums) {
   *   int n = nums.size();
   *   if (n == 0) return 0;
   *   // dp[i] = length of LIS ending at index i
   *   vector<int> dp(n, 1);
   *   int maxLen = 1;
   *   for (int i = 1; i < n; ++i) {
   *     for (int j = 0; j < i; ++j) {
   *       if (nums[j] < nums[i]) {
   *         dp[i] = std::max(dp[i], dp[j] + 1);
   *       }
   *     }
   *     maxLen = std::max(maxLen, dp[i]);
   *   }
   *   return maxLen;
   * }
   */
};
// @lc code=end
