/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to evaluate a string expression containing additions and
 * subtractions of fractions (like "-1/2+1/2+1/3") and return the result as a
 * string in irreducible fraction form (e.g., "1/3"). The result must always be
 * in the form "numerator/denominator", even if the answer is an integer (e.g.,
 * "2/1" for 2).
 *
 * High-Level Summary:
 * ----
 * The solution involves parsing the input string to extract each fraction (with
 * its sign), then adding/subtracting them one by one. To add/subtract
 * fractions, we convert them to a common denominator, sum the numerators, and
 * finally reduce the result to its simplest form using the greatest common
 * divisor (GCD). The code is modularized into helper functions for parsing, GCD
 * calculation, and fraction addition.
 *
 * Time Complexity: O(N), where N is the length of the input string (since we
 * parse each character once and process up to 10 fractions). Space Complexity:
 * O(1), since we only store a constant number of variables (no extra data
 * structures proportional to input size).
 */

#include <cstdlib> // For std::stoi
#include <numeric> // For std::gcd (C++17 and above)
#include <string>  // For std::string

using std::string;

// @lc code=start
class Solution {
public:
  // Main function to perform fraction addition and subtraction
  string fractionAddition(string expression) {
    int numerator = 0;   // Accumulated numerator
    int denominator = 1; // Accumulated denominator (start with 1)

    size_t i = 0; // Index to traverse the expression

    // Parse and process each fraction in the expression
    while (i < expression.size()) {
      // Parse the next fraction (with sign) from the expression
      int next_num = 0, next_den = 1;
      parseNextFraction(expression, i, next_num, next_den);

      // Add the parsed fraction to the accumulated result
      addFraction(numerator, denominator, next_num, next_den);
    }

    // Reduce the final result to its irreducible form
    reduceFraction(numerator, denominator);

    // Format the result as a string "numerator/denominator"
    return std::to_string(numerator) + "/" + std::to_string(denominator);
  }

private:
  // Helper function to parse the next fraction (with sign) from the expression
  void parseNextFraction(const string &expr, size_t &idx, int &num, int &den) {
    int sign = 1; // Default sign is positive

    // Check for explicit '+' or '-' sign
    if (expr[idx] == '+' || expr[idx] == '-') {
      sign = (expr[idx] == '-') ? -1 : 1;
      ++idx;
    }

    // Parse numerator
    int numerator = 0;
    while (idx < expr.size() && isdigit(expr[idx])) {
      numerator = numerator * 10 + (expr[idx] - '0');
      ++idx;
    }

    // Skip the '/' character
    ++idx;

    // Parse denominator
    int denominator = 0;
    while (idx < expr.size() && isdigit(expr[idx])) {
      denominator = denominator * 10 + (expr[idx] - '0');
      ++idx;
    }

    num = sign * numerator;
    den = denominator;
  }

  // Helper function to add a fraction (num2/den2) to (num1/den1)
  void addFraction(int &num1, int &den1, int num2, int den2) {
    // Find common denominator and add numerators
    int lcm = den1 * den2 / gcd(den1, den2); // Least common multiple
    num1 = num1 * (lcm / den1) + num2 * (lcm / den2);
    den1 = lcm;
    // Reduce after each addition to prevent overflow
    reduceFraction(num1, den1);
  }

  // Helper function to reduce a fraction to its irreducible form
  void reduceFraction(int &num, int &den) {
    int divisor = gcd(abs(num), den);
    num /= divisor;
    den /= divisor;
    // Ensure denominator is always positive
    if (den < 0) {
      num = -num;
      den = -den;
    }
  }

  // Helper function to compute the greatest common divisor (GCD)
  int gcd(int a, int b) {
#if __cplusplus >= 201703L
    // Use std::gcd if available (C++17 and above)
    return std::gcd(a, b);
#else
    // Otherwise, implement Euclidean algorithm
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
#endif
  }
};
// @lc code=end
