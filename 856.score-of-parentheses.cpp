/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

/*
 * Brief Digested Understanding:
 * ----
 * The heart of this problem is: given a string of balanced parentheses, compute
 * its "score" based on three rules: a pair "()" is worth 1, two adjacent
 * balanced strings are worth their sum, and enclosing a balanced string in
 * parentheses doubles its score. So, you recursively split and aggregate or
 * double scores based on nesting structure. The main challenge is handling both
 * adjacent and nested layers correctly, and traversing the string efficiently
 * without error-prone parsing.
 *
 * High-Level Summary:
 * ----
 * We'll solve this by using a stack to track scores at different levels of
 * parenthesis nesting. Each time we see '(', we push a zero onto the stack to
 * mark starting a new group. When we encounter ')', we pop from the stack: if
 * the top is zero, it means we just closed a '()', so we push(1), as per the
 * rules. If the top is nonzero, it means we completed a nested group whose
 * score should be doubled, so we pop and push(2 * groupScore). This handles
 * both direct pairs and nesting. Finally, summing elements in the stack gives
 * the result. This is O(N) time and O(N) space for stack, with all logic
 * encapsulated in helper functions for clarity.
 */

#include <stack>  // For std::stack to manage nesting
#include <string> // For std::string

using std::stack;
using std::string;

// @lc code=start
class Solution {
public:
  int scoreOfParentheses(string s) {
    // Use a stack to track the score at each level of nesting
    stack<int> scoreStack;
    // Initialize the stack with zero, representing the outermost score
    // accumulator
    scoreStack.push(0);

    // Process each character in the input string
    for (char c : s) {
      if (c == '(') {
        // Start a new group: push 0 to represent the score accumulated within
        // these parentheses
        scoreStack.push(0);
      } else {
        // c == ')': Finish the current group
        int innerScore = scoreStack.top();
        scoreStack.pop();
        if (innerScore == 0) {
          // Direct pair '()' encountered, score is 1
          scoreStack.top() += 1;
        } else {
          // Completed a group around some score: score doubles per rules
          scoreStack.top() += 2 * innerScore;
        }
        // After processing, scoreStack's top holds the total up to this point
      }
    }
    // The final result is on the top of the stack
    return scoreStack.top();
  }
};
// @lc code=end
