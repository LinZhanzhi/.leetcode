/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to evaluate a mathematical expression given as a string,
 * which contains non-negative integers and the operators '+', '-', '*', and
 * '/'. The expression may have spaces, and integer division should truncate
 * toward zero. We must parse the string, handle operator precedence
 * (multiplication/division before addition/subtraction), and compute the result
 * without using any built-in string evaluation functions.
 *
 * High-Level Summary:
 * ----
 * The solution processes the string from left to right, building numbers and
 * applying operators as they appear. To handle operator precedence, we use a
 * stack: for '+' and '-', we push the number (or its negative) onto the stack;
 * for '*' and '/', we pop the last number, perform the operation, and push the
 * result back. At the end, we sum all numbers in the stack to get the final
 * result.
 *
 * Time Complexity: O(N), where N is the length of the string (each character is
 * processed once). Space Complexity: O(N), in the worst case (all numbers are
 * added/subtracted, so the stack grows with input size).
 */

#include <cctype> // For std::isdigit
#include <stack>  // For std::stack
#include <string> // For std::string

using std::stack;
using std::string;

// @lc code=start
class Solution {
public:
  int calculate(string s) {
    stack<int> stk;   // Stack to store numbers for final summation
    int num = 0;      // Current number being built from digits
    char op = '+';    // Previous operator, initialized to '+'
    int n = s.size(); // Length of the input string

    // Iterate through each character in the string
    for (int i = 0; i < n; ++i) {
      char c = s[i];

      // If the character is a digit, build the current number
      if (std::isdigit(c)) {
        num = num * 10 + (c - '0');
      }

      // If the character is an operator or we're at the end of the string,
      // it's time to process the previous operator and number
      if ((!std::isdigit(c) && !std::isspace(c)) || i == n - 1) {
        // Handle the previous operator
        if (op == '+') {
          // For '+', push the number as is
          stk.push(num);
        } else if (op == '-') {
          // For '-', push the negative of the number
          stk.push(-num);
        } else if (op == '*') {
          // For '*', pop the last number, multiply, and push the result
          int last = stk.top();
          stk.pop();
          stk.push(last * num);
        } else if (op == '/') {
          // For '/', pop the last number, divide (truncate toward zero), and
          // push the result
          int last = stk.top();
          stk.pop();
          stk.push(last / num);
        }
        // Update the operator to the current one
        op = c;
        // Reset the current number for the next iteration
        num = 0;
      }
    }

    // Sum all numbers in the stack to get the final result
    int result = 0;
    while (!stk.empty()) {
      result += stk.top();
      stk.pop();
    }
    return result;
  }
};
// @lc code=end
