/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// Brief Digested Understanding:
// ----
// This problem is about solving a simple linear equation in one variable, 'x',
// where the equation is given as a string. The equation may have terms with 'x'
// (with or without coefficients), integer constants, and uses only '+' and '-'
// operators. The goal is to find the integer value of 'x' that satisfies the
// equation, or to determine if there are no solutions or infinitely many
// solutions. The answer should be returned as a string in the required format.
//
// The key is to parse both sides of the equation, collect the total
// coefficients of 'x' and the constants, and then solve for 'x' if possible.

// High-Level Summary:
// ----
// The approach is to split the equation into left and right sides at the '='.
// For each side, we parse the string to sum up the coefficients of 'x' and the
// constants. We then bring all 'x' terms to one side and all constants to the
// other, resulting in an equation of the form ax = b. If a == 0 and b == 0,
// there are infinite solutions. If a == 0 and b != 0, there is no solution.
// Otherwise, x = b / a. We use helper functions to modularize the parsing of
// each side. The time complexity is O(N), where N is the length of the
// equation, and space complexity is O(1) since we only store a few integers.

#include <string>  // For std::string
#include <utility> // For std::pair

using std::pair;
using std::string;

// @lc code=start
class Solution {
public:
  // Main function to solve the equation
  string solveEquation(string equation) {
    // Split the equation into left and right parts at '='
    size_t eq_pos = equation.find('=');
    string left = equation.substr(0, eq_pos);
    string right = equation.substr(eq_pos + 1);

    // Parse both sides to get (x coefficient, constant sum)
    pair<int, int> leftPair = parseSide(left);
    pair<int, int> rightPair = parseSide(right);

    // Move all x terms to the left, constants to the right
    int xCoeff = leftPair.first - rightPair.first;
    int constSum = rightPair.second - leftPair.second;

    // Analyze the result to determine the solution type
    if (xCoeff == 0) {
      if (constSum == 0) {
        return "Infinite solutions";
      } else {
        return "No solution";
      }
    } else {
      // Integer division is safe due to problem constraints
      int xValue = constSum / xCoeff;
      return "x=" + std::to_string(xValue);
    }
  }

private:
  // Helper function to parse one side of the equation
  // Returns a pair: (total x coefficient, total constant sum)
  pair<int, int> parseSide(const string &s) {
    int xCoeff = 0;   // Accumulates coefficients of 'x'
    int constSum = 0; // Accumulates constant terms
    int n = s.size();
    int i = 0;

    while (i < n) {
      int sign = 1; // Default sign is positive

      // Handle explicit '+' or '-' sign
      if (s[i] == '+') {
        sign = 1;
        ++i;
      } else if (s[i] == '-') {
        sign = -1;
        ++i;
      }

      int num = 0;
      bool isNumber = false;

      // Parse the number (if any)
      while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        ++i;
        isNumber = true;
      }

      // Check if the term is an 'x' term
      if (i < n && s[i] == 'x') {
        // If no number before 'x', the coefficient is 1 (or -1)
        if (!isNumber)
          num = 1;
        xCoeff += sign * num;
        ++i; // Move past 'x'
      } else {
        // It's a constant term
        constSum += sign * num;
      }
    }
    return {xCoeff, constSum};
  }
};
// @lc code=end
