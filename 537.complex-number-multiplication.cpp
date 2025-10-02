/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is about multiplying two complex numbers, each given as a string
 * in the form "a+bi". Each part (real and imaginary) is an integer, and the
 * result should also be returned as a string in the same format. The
 * multiplication of two complex numbers (a+bi) and (c+di) is (ac - bd) + (ad +
 * bc)i, using the rule that i^2 = -1.
 *
 * High-Level Summary:
 * ----
 * The solution involves three main steps:
 *   1. Parse each input string to extract the real and imaginary integer parts.
 *   2. Perform the multiplication using the formula for complex numbers.
 *   3. Format the result back into the required string form.
 *
 * The parsing is handled by a helper function for clarity and modularity.
 * The overall time complexity is O(1) since the input size is fixed and small.
 * Space complexity is also O(1) as only a few integer variables are used.
 */

#include <sstream> // For std::stringstream
#include <string>  // For std::string

using std::string;

// @lc code=start
class Solution {
public:
  // Helper function to parse a complex number string "a+bi" into a pair of
  // integers (a, b)
  std::pair<int, int> parseComplex(const string &num) {
    // Find the position of '+' which separates real and imaginary parts
    size_t plusPos = num.find('+');
    // Extract the real part (substring before '+')
    int real = std::stoi(num.substr(0, plusPos));
    // Extract the imaginary part (substring after '+', remove trailing 'i')
    int imag = std::stoi(num.substr(plusPos + 1, num.length() - plusPos - 2));
    // Return as a pair (real, imaginary)
    return {real, imag};
  }

  // Main function to multiply two complex numbers represented as strings
  string complexNumberMultiply(string num1, string num2) {
    // Parse both input strings to get their real and imaginary parts
    auto [a, b] = parseComplex(num1); // num1 = a + bi
    auto [c, d] = parseComplex(num2); // num2 = c + di

    // Compute the real part: (a * c - b * d)
    int realPart = a * c - b * d;
    // Compute the imaginary part: (a * d + b * c)
    int imagPart = a * d + b * c;

    // Format the result as "real+imagi"
    return std::to_string(realPart) + "+" + std::to_string(imagPart) + "i";
  }
};
// @lc code=end
