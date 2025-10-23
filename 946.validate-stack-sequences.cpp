/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// Brief Digested Understanding:
// -----
// This problem is about simulating a stack: given two distinct integer arrays,
// `pushed` and `popped`, can you perform a series of push and pop operations
// such that pushing values from `pushed` in order and popping some at any time
// will produce the `popped` sequence? The heart of the question is: is the
// `popped` sequence a possible legal sequence of pops for a stack that is being
// filled using `pushed`?

// High-Level Summary:
// -----
// We'll use a simulated stack to trace the order of push and pop operations.
// For each value in `pushed`, we push to our stack. After each push, if the top
// of the stack matches the next value in `popped`, we pop as many times as we
// can until this isn't true. At the end, if we've successfully matched all
// `popped` values, the sequence is valid. This algorithm works in O(N) time and
// space (where N is the length of `pushed`), using a vector as the stack for
// fast push/pop operations.

// @lc code=start
#include <vector>  // For std::vector to allow using vector<int>
using std::vector; // Bring vector into current namespace for easier use

class Solution {
public:
  // Main function to validate possible stack sequences
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    // Helper function to simulate the push/pop process
    return isValidStackSequence(pushed, popped);
  }

private:
  // Helper: Simulates the stack operations and checks if `popped` can be
  // produced
  bool isValidStackSequence(const vector<int> &pushed,
                            const vector<int> &popped) {
    vector<int> stack; // This will act as our stack
    int popIndex = 0;  // Index in `popped` we are currently matching

    // Iterate over each value to push it onto the stack, in order
    for (int val : pushed) {
      stack.push_back(val); // Push current value onto the stack

      // Continuously pop if the top of the stack matches the next expected
      // popped value This simulates popping as soon as it's legal, as often as
      // possible
      while (!stack.empty() && stack.back() == popped[popIndex]) {
        stack.pop_back(); // Pop off the stack
        popIndex++;       // Advance to next value in popped sequence
      }
    }

    // At the end, if we've matched every value in `popped`, the sequence is
    // valid (stack should be empty, and we've advanced through all of popped)
    return popIndex == static_cast<int>(popped.size());
  }
};
// @lc code=end
