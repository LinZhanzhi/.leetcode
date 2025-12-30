/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// Brief Digested Understanding:
// -----
// The problem asks us to calculate the sum of the minimum values from all
// contiguous subarrays of a given integer array. We must efficiently find,
// for each subarray, its minimum value, then sum all those values together.
// Since iterating over all subarrays is too slow for large arrays, we need an
// optimized approach that avoids redundant computation. Modular arithmetic is
// required since the answer can get very large.

// High-Level Summary:
// -----
// To solve this efficiently, the key insight is to use a monotonic stack to
// count, for each position, how many subarrays it is the minimum for.
// Specifically, for each element, we determine the number of subarrays where
// that element is the minimum by counting how many contiguous segments extend
// to the left and right where it remains the least value. We use two monotonic
// stacks to precompute these "spans". The sum is then the product of the value,
// its "span to the left", and its "span to the right" for all positions, summed
// up. This approach runs in O(n) time and O(n) space, where n is the array
// size, making it optimal for large inputs.

// Include vector and stack libraries for array manipulation and stack
// operations.
#include <stack>
#include <vector>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the sum of subarray minimums.
  int sumSubarrayMins(vector<int> &arr) {
    const int MOD = 1e9 + 7; // To keep answer within bounds as required.
    int n = arr.size();

    // Arrays to store the count of subarrays ending and starting at each index,
    // where arr[i] is the minimum.
    vector<int> left(n, 0);  // How many consecutive elements to the left
                             // (including i) where arr[i] is the minimum
    vector<int> right(n, 0); // How many consecutive elements to the right
                             // (including i) where arr[i] is the minimum

    // Stack for calculating left (previous less element)
    stack<int> mono_stack_left;
    for (int i = 0; i < n; ++i) {
      // Maintain a stack of indices with increasing arr[] values.
      // For duplicates, we want farther left, so use '>'
      while (!mono_stack_left.empty() && arr[mono_stack_left.top()] > arr[i]) {
        mono_stack_left.pop();
      }
      if (mono_stack_left.empty()) {
        // If nothing is less, then span is i+1 (from 0 to i)
        left[i] = i + 1;
      } else {
        // Else, distance to the previous less element
        left[i] = i - mono_stack_left.top();
      }
      mono_stack_left.push(
          i); // Add current index for processing future elements
    }

    // Stack for calculating right (next less element)
    stack<int> mono_stack_right;
    for (int i = n - 1; i >= 0; --i) {
      // Maintain a stack of indices with increasing arr[] values.
      // For duplicates, to avoid double-counting, we use '>='
      while (!mono_stack_right.empty() &&
             arr[mono_stack_right.top()] >= arr[i]) {
        mono_stack_right.pop();
      }
      if (mono_stack_right.empty()) {
        // If nothing is less, then span is up to the end of array
        right[i] = n - i;
      } else {
        // Else, distance to the next less element
        right[i] = mono_stack_right.top() - i;
      }
      mono_stack_right.push(i);
    }

    // Now, for each element, its contribution is arr[i] * left[i] * right[i].
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      // Multiply as long long to avoid overflow, then take mod.
      long long contrib =
          (static_cast<long long>(arr[i]) * left[i] * right[i]) % MOD;
      result = (result + contrib) % MOD;
    }
    return static_cast<int>(result);
  }
};
// @lc code=end
