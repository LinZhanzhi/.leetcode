/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a circular array of integers. For each element, we need to find
 * the next greater element as we traverse the array (wrapping around to the
 * start if needed). If no such greater element exists, we return -1 for that
 * position. The challenge is to efficiently find, for every index, the next
 * number that is greater than the current one, considering the circular nature
 * of the array.
 *
 * High-Level Summary:
 * ----
 * The solution uses a stack to keep track of indices whose next greater element
 * hasn't been found yet. We simulate traversing the array twice (2 * n
 * iterations) to handle the circular property. For each element, we pop from
 * the stack until we find a greater element or the stack is empty. The result
 * array is initialized with -1s, and we update it when we find a next greater
 * element. This approach ensures O(n) time complexity and O(n) space
 * complexity, where n is the length of the input array.
 */

#include <stack>  // Include stack for the monotonic stack approach
#include <vector> // Include vector for dynamic array support

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the next greater elements in a circular array
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();       // Get the size of the input array
    vector<int> result(n, -1); // Initialize result array with -1s
    stack<int> st;             // Stack to keep indices of elements

    // Helper function to process the array twice for circularity
    processCircular(nums, result, st, n);

    return result; // Return the filled result array
  }

private:
  // Helper function to process the array in a circular manner
  void processCircular(const vector<int> &nums, vector<int> &result,
                       stack<int> &st, int n) {
    // We iterate from 0 to 2*n - 1 to simulate circular traversal
    for (int i = 0; i < 2 * n; ++i) {
      int currentIndex = i % n; // Wrap around using modulo for circularity

      // While stack is not empty and current element is greater than the
      // element at the index on top of the stack
      while (!st.empty() && nums[currentIndex] > nums[st.top()]) {
        int idx = st.top(); // Get the index from the top of the stack
        st.pop();           // Remove it from the stack
        result[idx] = nums[currentIndex]; // Update result for that index
      }

      // Only push indices from the first pass (i < n) to avoid duplicates
      if (i < n) {
        st.push(currentIndex);
      }
      // We do not push indices in the second pass, as all indices are already
      // in the stack from the first pass
    }
    // After the loop, any indices left in the stack do not have a next greater
    // element, so their result remains -1
  }
};
// @lc code=end
