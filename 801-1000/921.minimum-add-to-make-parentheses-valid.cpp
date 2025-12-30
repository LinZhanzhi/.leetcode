/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding the smallest number of insertions (either '('
 * or ')') required to turn a given string of parentheses into a valid one. A
 * valid sequence never has a ')' without a matching '(', and every '(' must be
 * closed by a later ')'. The goal is to compute the minimum "fixes" to make an
 * unbalanced or incomplete parentheses string valid, considering both cases
 * where we have missing '(' and missing ')'.
 *
 * High-Level Summary:
 * ----
 * We traverse the string, maintaining a counter (let's call it "balance") to
 * track the difference between opening and closing parentheses needed for
 * validity. If we see '(', we expect a future ')'. If we see ')', we decrease
 * balance. If balance goes negative—that is, we have an unmatched ')', we know
 * we need to insert an extra '(' to fix this part. After traversing the string,
 * if any unclosed '(' remain (i.e., balance > 0), each one will need to be
 * closed by inserting a ')'.
 *
 * Algorithm:
 *   - Iterate through each character in the string
 *   - Track current need for ')'
 *   - If ')' appears without a matching '(', count it as needing an extra '('
 *   - After traversal, the remaining unmatched '(' (the balance) needs extra
 * ')'
 *   - Sum these counts for the total answer
 *
 * Time complexity: O(n), where n is the length of s.
 * Space complexity: O(1). No extra data structures beyond a few variables.
 */

// Include the necessary header for std::string and use the std namespace for
// brevity.
#include <string>
using std::string;

// @lc code=start
class Solution {
public:
  // Main function to calculate minimum insertions to make the parentheses valid
  int minAddToMakeValid(string s) {
    // Helper function to compute the minimum additions required
    return computeMinInsertions(s);
  }

private:
  // Helper function to encapsulate the main logic
  int computeMinInsertions(const string &s) {
    int neededOpens = 0;  // Counts the number of '(' needed to fix excess ')'
    int neededCloses = 0; // Tracks how many ')' are needed to close all opens

    // Iterate through each character in the input string s
    for (char c : s) {
      if (c == '(') {
        // Each '(' increases the count of needed closing parentheses
        neededCloses++;
      } else if (c == ')') {
        // Each ')' tries to close an outstanding '('
        if (neededCloses > 0) {
          // There's a pending '(', so use one up
          neededCloses--;
        } else {
          // No open '(' available to match—must insert an extra '('
          neededOpens++;
        }
      }
      // No other characters as per problem constraints; no handling needed
    }
    // At the end, neededOpens counts unmatched ')', neededCloses counts
    // unmatched '(' Total insertions is both summed
    return neededOpens + neededCloses;
  }
};
// @lc code=end
