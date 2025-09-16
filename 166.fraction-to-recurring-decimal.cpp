/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    // If numerator is zero, the result is always "0"
    if (numerator == 0)
      return "0";
    string res;
    // Handle the sign: result is negative if exactly one of numerator or
    // denominator is negative
    if ((numerator < 0) ^ (denominator < 0))
      res += "-";
    // Convert both numbers to long long and take absolute value to avoid
    // overflow (e.g., INT_MIN)
    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);
    // Append the integer part of the division
    res += to_string(n / d);
    long long rem = n % d; // Get the initial remainder
    // If there is no remainder, return the result (no fractional part)
    if (rem == 0)
      return res;
    // There is a fractional part, so add the decimal point
    res += ".";
    // Map to store the position of each remainder to detect cycles (repeats)
    unordered_map<long long, int> rem_pos;
    // Simulate the division process for the fractional part
    while (rem) {
      // If this remainder has been seen before, a repeating cycle is detected
      if (rem_pos.count(rem)) {
        // Insert '(' at the position where this remainder first appeared
        // string& insert(size_t pos, size_t count, char ch);
        // insert(pos, count, ch) inserts count instances of character ch at
        // position pos
        res.insert(rem_pos[rem], 1, '(');
        // Append ')' to close the repeating part
        res += ")";
        break;
      }
      // Store the current position of the remainder
      rem_pos[rem] = res.size();
      rem *= 10; // Multiply remainder by 10 for the next digit
      // Append the next digit of the fractional part
      res += to_string(rem / d);
      // Update the remainder
      rem %= d;
    }
    return res;
  }
};
// @lc code=end
