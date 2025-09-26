/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to determine if a given string of digits can be split
 * into at least three numbers such that, starting from the third number, each
 * number is the sum of the previous two. The numbers must not have leading
 * zeros (unless the number itself is zero). The challenge is to try all
 * possible ways to split the string into the first two numbers and then check
 * if the rest of the string can be built as an additive sequence.
 *
 * High-Level Summary:
 * ----
 * The solution tries all possible splits for the first and second numbers (with
 * lengths up to half the string), making sure there are no leading zeros. For
 * each split, it simulates the additive sequence by adding the previous two
 * numbers (as strings, to avoid integer overflow) and checking if the next part
 * of the string matches the sum. If the entire string can be consumed in this
 * way, it returns true. Otherwise, it tries the next possible split. The
 * approach uses string addition to handle very large numbers. The time
 * complexity is O(N^3), where N is the length of the string, due to the nested
 * loops and string operations.
 */

#include <string> // Include string for std::string
using std::string;

// @lc code=start
class Solution {
public:
  // Helper function to add two numbers represented as strings.
  // This avoids integer overflow for very large numbers.
  string addStrings(const string &num1, const string &num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    // Add digits from right to left
    while (i >= 0 || j >= 0 || carry) {
      int n1 = (i >= 0) ? num1[i--] - '0' : 0; // Get digit or 0
      int n2 = (j >= 0) ? num2[j--] - '0' : 0; // Get digit or 0
      int sum = n1 + n2 + carry;
      result.insert(result.begin(), sum % 10 + '0'); // Prepend digit
      carry = sum / 10;                              // Update carry
    }
    return result;
  }

  // Recursive helper to check if the sequence starting at 'start' is valid
  // with previous two numbers num1 and num2.
  // Returns true if the rest of the string can be built as an additive
  // sequence.
  bool check(const string &num, int start, const string &num1,
             const string &num2) {
    // If we've reached the end of the string, and have at least 3 numbers, it's
    // valid
    if (start == num.size()) {
      return true;
    }
    // Compute the sum of the last two numbers as a string
    string sum = addStrings(num1, num2);
    int sumLen = sum.size();
    // If the next part of num doesn't match the sum, return false
    if (start + sumLen > num.size() || num.substr(start, sumLen) != sum) {
      return false;
    }
    // Continue recursively with the next two numbers
    return check(num, start + sumLen, num2, sum);
  }

  // Main function to check if the string is an additive number
  bool isAdditiveNumber(string num) {
    int n = num.size();
    // The first number can be at most n-2 digits (since we need at least 3
    // numbers)
    for (int i = 1; i <= n - 2; ++i) {
      // Skip if the first number has leading zeros (unless it's "0")
      if (num[0] == '0' && i > 1)
        break;
      string num1 = num.substr(0, i);
      // The second number starts after the first and can be at most n-i-1
      // digits
      for (int j = 1; j <= n - i - 1; ++j) {
        // Skip if the second number has leading zeros (unless it's "0")
        if (num[i] == '0' && j > 1)
          break;
        string num2 = num.substr(i, j);
        // The sequence must have at least 3 numbers, so ensure remaining length
        // is enough
        if (n - (i + j) < std::max(i, j))
          continue;
        // Use recursion to check the rest of the string
        if (check(num, i + j, num1, num2))
          return true;
      }
    }
    // No valid sequence found
    return false;
  }
};
// @lc code=end
