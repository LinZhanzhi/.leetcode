/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to count the number of contiguous subarrays (subsequences
 * of consecutive elements) of length at least 3 in which the difference between
 * every pair of consecutive elements is the same. These are called "arithmetic
 * slices." For example, in [1,2,3,4], the subarrays [1,2,3], [2,3,4], and
 * [1,2,3,4] are all arithmetic slices. The goal is to efficiently count all
 * such subarrays in the given array.
 *
 * High-Level Summary:
 * ----
 * The solution uses a dynamic programming approach. We iterate through the
 * array and, for each position, check if the last three elements form an
 * arithmetic sequence. If they do, we can extend any arithmetic slice ending at
 * the previous position by one, and we also get a new slice of length 3. We
 * keep a running count of the number of arithmetic slices ending at each
 * position and sum them up for the final answer.
 *
 * Time Complexity: O(n), where n is the length of the array, since we make a
 * single pass. Space Complexity: O(1), since we only use a few variables for
 * counting.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    // The total number of arithmetic slices found
    int total = 0;
    // The number of arithmetic slices ending at the previous index
    int curr = 0;
    // We need at least 3 elements to form an arithmetic slice
    for (int i = 2; i < nums.size(); ++i) {
      // Check if the current three elements form an arithmetic sequence
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        // If so, we can extend the previous count by 1
        // (all slices ending at i-1 can be extended to i)
        // and we get a new slice of length 3
        curr += 1;
        total += curr;
      } else {
        // If not, reset the current count
        curr = 0;
      }
    }
    // Return the total number of arithmetic slices found
    return total;
  }
};
// @lc code=end
