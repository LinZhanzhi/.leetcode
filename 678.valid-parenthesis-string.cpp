/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to determine if a string made up of '(', ')', and '*'
 * can be interpreted as a valid sequence of parentheses. The twist is that
 * each '*' can act as a '(', a ')', or be ignored (empty). The string is valid
 * if, after interpreting all '*', every '(' has a matching ')', and the order
 * of parentheses is correct.
 *
 * High-Level Summary:
 * ----
 * We'll solve this problem using a greedy approach that tracks the possible
 * range of open left parentheses as we scan the string. We maintain two
 * counters: one for the minimum possible number of open '(' (treating '*' as
 * ')'), and one for the maximum possible number of open '(' (treating '*' as
 * '('). If at any point the maximum open count drops below zero, the string
 * cannot be valid. At the end, if the minimum open count is zero, the string
 * can be valid. This approach is efficient (O(n) time, O(1) space) and avoids
 * exponential backtracking.
 */

// @lc code=start
#include <string> // Include string header for std::string

using std::string; // Bring std::string into the current namespace

class Solution {
public:
  // Main function to check if the string is a valid parenthesis string
  bool checkValidString(string s) {
    // Helper function to perform the greedy check
    return isValidWithGreedy(s);
  }

private:
  // Helper function that implements the greedy algorithm
  bool isValidWithGreedy(const string &s) {
    int minOpen = 0; // Minimum possible number of open '(' at this point
    int maxOpen = 0; // Maximum possible number of open '(' at this point

    // Iterate through each character in the string
    for (char c : s) {
      if (c == '(') {
        // '(' always increases both min and max open counts
        minOpen += 1;
        maxOpen += 1;
      } else if (c == ')') {
        // ')' decreases both min and max open counts
        minOpen -= 1;
        maxOpen -= 1;
      } else if (c == '*') {
        // '*' can be '(', ')', or empty:
        // - If '*'' is '(', maxOpen increases
        // - If '*'' is ')', minOpen decreases
        // - If '*'' is empty, counts stay the same
        minOpen -= 1; // Treat '*' as ')'
        maxOpen += 1; // Treat '*' as '('
      }

      // If maxOpen drops below 0, too many ')' have occurred
      if (maxOpen < 0) {
        return false;
      }

      // minOpen should never be negative; reset to 0 if it is
      // (since we can't have negative open parentheses)
      if (minOpen < 0) {
        minOpen = 0;
      }
    }

    // If minOpen is 0, all open '(' can be matched; otherwise, not valid
    return minOpen == 0;
  }
};
// @lc code=end
