/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to check if there exists a subsequence of three numbers
 * in the array (nums[i], nums[j], nums[k] with i < j < k) such that nums[i] <
 * nums[k] < nums[j]. This is called a "132 pattern" because the values are in
 * the order 1 < 3 < 2, but the indices are increasing. The challenge is to
 * efficiently detect such a pattern in the array.
 *
 * High-Level Summary:
 * ----
 * To efficiently find a 132 pattern, we scan the array from right to left. We
 * use a stack to keep track of possible "nums[k]" (the '2' in the pattern)
 * candidates, and a variable to store the largest valid "nums[k]" found so far.
 * For each number (considered as a possible "nums[i]"), we check if it can be
 * the "1" in the pattern (i.e., if it's less than the largest "nums[k]" found
 * so far). If so, we return true. This approach ensures O(n) time complexity by
 * using a monotonic stack, and O(n) space for the stack.
 */

#include <climits> // Include climits for INT_MIN
#include <stack>   // Include stack for using std::stack
#include <vector>  // Include vector for using std::vector

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find if a 132 pattern exists in the array
  bool find132pattern(vector<int> &nums) {
    // Edge case: If there are fewer than 3 numbers, no pattern is possible
    if (nums.size() < 3)
      return false;

    // This stack will store possible "nums[k]" (the '2' in the 132 pattern) in
    // decreasing order
    stack<int> possibleNumKStack;
    // This variable will keep track of the largest "nums[k]" (the '2') found so
    // far
    int maxNumK = INT_MIN;

    // Traverse the array from right to left, treating nums[i] as a possible
    // "nums[i]" (the '1')
    for (int idx_i = nums.size() - 1; idx_i >= 0; --idx_i) {
      int candidateNumI = nums[idx_i]; // candidate for nums[i] (the '1')
      // If candidateNumI is less than the largest "nums[k]" found so far,
      // then we have found nums[i] < nums[k] < nums[j] for some j > i
      if (candidateNumI < maxNumK) {
        return true;
      }
      // While the stack is not empty and candidateNumI is greater than the top
      // of the stack, pop from the stack and update maxNumK. This means
      // candidateNumI is a possible "nums[j]" (the '3'), and stack top is a
      // possible "nums[k]" (the '2').
      while (!possibleNumKStack.empty() &&
             candidateNumI > possibleNumKStack.top()) {
        maxNumK = possibleNumKStack.top(); // Update maxNumK to the last popped
                                           // value (best "2" so far)
        possibleNumKStack.pop();
      }
      // Push candidateNumI onto the stack as a potential "nums[k]" (the '2')
      // for future iterations
      possibleNumKStack.push(candidateNumI);
    }
    // If we finish the loop without finding a pattern, return false
    return false;
  }
};
/*
 * Example Walkthrough: Input: nums = [3, 1, 4, 2]
 * ----
 * Let's step through the algorithm with this input to see how the stack and
 * maxNumK evolve:
 *
 * Initial state:
 *   nums = [3, 1, 4, 2]
 *   possibleNumKStack = empty
 *   maxNumK = INT_MIN
 *
 * We process from right to left (indices 3 to 0):
 *
 * Step 1: idx_i = 3, candidateNumI = 2
 *   - candidateNumI < maxNumK? 2 < INT_MIN? No.
 *   - While stack not empty and 2 > stack.top()? Stack is empty, so skip.
 *   - Push 2 onto stack.
 *   Stack: [2]
 *   maxNumK: INT_MIN
 *
 * Step 2: idx_i = 2, candidateNumI = 4
 *   - candidateNumI < maxNumK? 4 < INT_MIN? No.
 *   - While stack not empty and 4 > stack.top()? 4 > 2, so:
 *       - maxNumK = stack.top() = 2
 *       - Pop stack (stack becomes empty)
 *   - Push 4 onto stack.
 *   Stack: [4]
 *   maxNumK: 2
 *
 * Step 3: idx_i = 1, candidateNumI = 1
 *   - candidateNumI < maxNumK? 1 < 2? Yes!
 *   - We have found a 132 pattern: nums[i]=1, nums[k]=2, nums[j]=4 (i=1, k=3,
 * j=2)
 *   - The function returns true here.
 *
 * Step 4: (Not reached, as we already returned true)
 *
 * Summary:
 *   - The stack helps us keep track of possible "2"s (nums[k]) for the 132
 * pattern.
 *   - maxNumK is updated to the largest "2" found so far.
 *   - When we find a candidateNumI < maxNumK, we have found the pattern.
 *
 * This example demonstrates how the algorithm efficiently detects the 132
 * pattern in a single pass.
 */
// @lc code=end
