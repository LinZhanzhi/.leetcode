/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given an array of integers, we need to create a new array where each element
 * at index i is the product of all the numbers in the original array except the
 * one at i. We must do this without using division, and in linear time. The
 * challenge is to efficiently compute the product for each index without
 * recalculating the whole product for every position.
 *
 * High-Level Summary:
 * ----
 * The solution uses two passes over the array:
 *   1. In the first pass (left to right), we compute the product of all
 * elements to the left of each index and store it in the result array.
 *   2. In the second pass (right to left), we multiply each result by the
 * product of all elements to the right. This way, for each index, the result is
 * the product of all elements except itself. The algorithm runs in O(n) time
 * and uses O(1) extra space (excluding the output array).
 *
 * Time Complexity: O(n), where n is the length of nums.
 * Space Complexity: O(1) extra space (output array does not count).
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();      // Get the size of the input array
    vector<int> answer(n, 1); // Initialize the answer array with 1s

    // First pass: Compute the prefix product for each index
    // prefix stores the product of all elements to the left of the current
    // index
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
      answer[i] =
          prefix; // Set answer[i] to the product of all elements to the left
      prefix *= nums[i]; // Update prefix to include nums[i] for the next index
      // After this loop, answer[i] contains the product of all elements to the
      // left of i
    }

    // Second pass: Compute the suffix product for each index and multiply with
    // the prefix product suffix stores the product of all elements to the right
    // of the current index
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
      answer[i] *=
          suffix; // Multiply with the product of all elements to the right
      suffix *= nums[i]; // Update suffix to include nums[i] for the next index
                         // to the left
      // After this loop, answer[i] contains the product of all elements except
      // nums[i]
    }

    // Return the final answer array
    return answer;
  }
};
// @lc code=end
