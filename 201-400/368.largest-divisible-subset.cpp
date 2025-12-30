/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the largest possible subset of a given list of
 * unique positive integers such that for every pair of numbers in the subset,
 * one number divides the other (i.e., for any two numbers in the subset, either
 * a % b == 0 or b % a == 0). The subset does not need to be contiguous, and if
 * there are multiple valid answers, any one is acceptable.
 *
 * High-Level Summary:
 * ----
 * The solution uses dynamic programming. First, we sort the input array to make
 * it easier to check divisibility (since if a divides b, a <= b). For each
 * number, we keep track of the size of the largest divisible subset ending at
 * that number, and we also remember the previous index in that subset for
 * reconstruction. After filling out these arrays, we reconstruct the largest
 * subset by backtracking from the index with the largest subset size. The time
 * complexity is O(n^2), where n is the number of elements, and the space
 * complexity is O(n) for the DP and parent arrays.
 */

#include <algorithm> // Include algorithm for sort and max_element
#include <vector>    // Include vector for dynamic arrays

using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    // Edge case: if nums is empty, return an empty vector
    if (nums.empty())
      return {};

    // Step 1: Sort the numbers to ensure that for any i < j, nums[i] <= nums[j]
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    // dp[i] will store the size of the largest divisible subset ending with
    // nums[i]
    vector<int> dp(
        n, 1); // Initialize all to 1 (each number is a subset of size 1)
    // parent[i] will store the index of the previous element in the subset
    // ending at i
    vector<int> parent(n, -1);

    int maxSize = 1;  // The size of the largest subset found so far
    int maxIndex = 0; // The index where the largest subset ends

    // Step 2: Build up the dp and parent arrays
    for (int i = 1; i < n; ++i) {
      // For each nums[i], check all previous numbers nums[j] (j < i)
      for (int j = 0; j < i; ++j) {
        // If nums[i] is divisible by nums[j], it can extend the subset ending
        // at j
        if (nums[i] % nums[j] == 0) {
          // If extending the subset at j gives a larger subset at i, update
          // dp[i] and parent[i]
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            parent[i] = j;
          }
        }
      }
      // Update maxSize and maxIndex if we found a larger subset
      if (dp[i] > maxSize) {
        maxSize = dp[i];
        maxIndex = i;
      }
    }

    // Step 3: Reconstruct the largest divisible subset
    vector<int> result;
    int curr = maxIndex;
    // Backtrack from maxIndex using the parent array to collect the subset
    // elements
    while (curr != -1) {
      result.push_back(nums[curr]);
      curr = parent[curr];
    }
    // The subset is built in reverse order, so reverse it before returning
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
