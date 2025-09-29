/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// Brief, Digested Understanding:
// ----
// The problem is to convert a string that represents a nested list of integers
// (with possible sublists) into a NestedInteger object. The string can be a
// single integer (like "324") or a nested structure (like "[123,[456,[789]]]")
// with arbitrary depth. The parser must correctly interpret brackets, commas,
// negative signs, and numbers, and build the corresponding nested data
// structure.

// High-Level Summary:
// ----
// The solution uses a stack to keep track of the current context (list nesting)
// as it parses the string from left to right. When encountering '[', it starts
// a new NestedInteger list and pushes it onto the stack. When encountering a
// number (including negative numbers), it parses the full number and adds it as
// a NestedInteger to the current list. When encountering ']', it pops the
// completed NestedInteger from the stack and adds it to the previous list (if
// any). If the input is just a number (no brackets), it returns a NestedInteger
// holding that integer. The algorithm runs in O(N) time and space, where N is
// the length of the string, since each character is processed once and the
// stack grows with the nesting depth.

// @lc code=start
#include <stack>
#include <string>

using std::stack;
using std::string;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
  NestedInteger deserialize(string s) {
    // If the string is empty, return an empty NestedInteger (edge case, not
    // expected per constraints)
    if (s.empty())
      return NestedInteger();

    // If the string does not start with '[', it must be a single integer
    // Example: "324"
    if (s[0] != '[') {
      // Convert the string to integer and return as a NestedInteger
      return NestedInteger(std::stoi(s));
    }

    // Stack to keep track of NestedInteger objects for each level of nesting
    stack<NestedInteger> stk;
    int n = s.size();
    int num = 0;           // To store the current number being parsed
    bool negative = false; // To track if the current number is negative
    bool hasNum = false;   // To track if we are currently parsing a number

    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == '[') {
        // Start a new NestedInteger list and push onto the stack
        stk.push(NestedInteger());
      } else if (c == '-') {
        // Negative sign detected, set the flag
        negative = true;
      } else if (isdigit(c)) {
        // Parse the digit, build the number
        num = num * 10 + (c - '0');
        hasNum = true; // Mark that we are parsing a number
      } else if (c == ',' || c == ']') {
        // If we have just finished parsing a number, add it to the current list
        if (hasNum) {
          if (negative)
            num = -num; // Apply negative sign if needed
          // Add the integer as a NestedInteger to the top NestedInteger in the
          // stack
          stk.top().add(NestedInteger(num));
          // Reset number parsing state
          num = 0;
          negative = false;
          hasNum = false;
        }
        // If ']' is encountered, we need to finish the current NestedInteger
        // list
        if (c == ']') {
          // If the stack has more than one NestedInteger, pop the top and add
          // it to the next one
          if (stk.size() > 1) {
            NestedInteger ni = stk.top();
            stk.pop();
            stk.top().add(ni);
          }
          // If only one NestedInteger is left, it will be returned at the end
        }
        // If ',' is encountered, just continue to the next element
      }
      // Any other character (should not occur per constraints) is ignored
    }
    // The result is the only NestedInteger left in the stack
    return stk.top();
  }
};
// @lc code=end
