/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// Brief Digested Understanding:
// ----
// The problem asks: For a given number n, what is the largest number less than
// or equal to n, whose digits strictly do not decrease from left to right? In
// simpler terms, you want to find a number <= n whose digits are sorted in
// non-decreasing order from left to right. The challenge is to carefully reduce
// digits from left-to-right if a decrease is detected, ensuring the property is
// satisfied for the whole number. Constraints are moderate (up to one billion),
// so the solution should be efficient without brute force.

// High-Level Summary:
// ----
// The approach is to process the number as a string of digits. Traverse
// left-to-right to find the first place where a digit decreases compared to its
// previous digit. Once a decreasing pair is found, we step back and decrement
// the prior digit, then set all following digits to '9' to get the largest
// possible monotone increasing number. This may have to be repeated as
// decrementing may cause further monotonicity violations to the left, so the
// process is cascaded if needed. Throughout, helper functions encapsulate
// string/number operations for clarity. Time complexity is O(d) where d is the
// number of digits (at most 10), so performance is not an issue. Space
// complexity is also O(d).

// @lc code=start
#include <string>
using std::string;

class Solution {
public:
  // Public function that finds the largest monotone increasing digits number <=
  // n
  int monotoneIncreasingDigits(int n) {
    // Convert the integer n to a mutable string to manipulate its digits
    // individually
    string digits = intToString(n);
    // Apply the main algorithm to adjust the string to monotone increasing
    // digits
    makeMonotoneIncreasing(digits);
    // Convert the resulting string back to integer to return as the answer
    return stringToInt(digits);
  }

private:
  // Helper function: Convert int to string
  string intToString(int n) {
    // Using std::to_string for clarity and efficiency
    return std::to_string(n);
  }

  // Helper function: Convert string to int
  int stringToInt(const string &s) {
    // Using std::stoi as the input string will always be a non-negative digit
    // string
    return std::stoi(s);
  }

  // Helper function that modifies the string to become the largest possible
  // monotone increasing number <= the original digit sequence
  void makeMonotoneIncreasing(string &digits) {
    // Find the index where the monotonicity breaks (i.e., digits[i] <
    // digits[i-1])
    int n = digits.length();
    int marker = n; // Position to start setting digits to '9'

    // Traverse digits right-to-left to find where decrease happens
    for (int i = n - 1; i > 0; --i) {
      // If the current digit is less than the one before it, we break
      // monotonicity
      if (digits[i] < digits[i - 1]) {
        // Decrement the digit before the violation by 1
        digits[i - 1]--;
        // Mark the position from here to set all following digits to '9'
        marker = i;
      }
    }
    // All digits after the marker should be set to '9'
    // This achieves the largest possible number less than original
    for (int i = marker; i < n; ++i) {
      digits[i] = '9';
    }
  }
};
/*
**Brief Digested Understanding:**
- This problem is really about finding the largest number less than or equal to
a given integer `n`, where the digits in the number are in non-decreasing order
from left to right. In other words, as you move from left to right, no digit
should be smaller than the one before.
- For example, for `n = 332`, we need the largest number ≤ 332 whose digits are
monotone increasing, i.e., every digit is at least as big as the previous one.

**High-Level Summary:**
- The main approach is to scan the number as a string from right to left.
Whenever we find a digit that is **greater** than the digit after it, we
decrease the earlier digit and set all subsequent digits to '9' (the largest
possible) to maximize the result.
- We'll use helper functions to convert back and forth between `int` and
`string` representations as well as to manipulate the digits.
- The time complexity is O(D), where D is the number of digits in `n`, and the
space complexity is also O(D) due to string conversion.

**Step by Step Example for Input: n = 332**
Let's trace how the program processes this input:

1. **Original number:** 332
2. **Convert to string:** "332"
3. **Right-to-left scan:**
   - At i=2 (digit '2'), compare with i=1 (digit '3'). Since '2' < '3', decrease
i=1 ('3' → '2'), and remember position 2 as the marker.
   - Next, at i=1 (now '2'), compare with i=0 (digit '3'). Again, '2' < '3', so
decrease i=0 ('3' → '2'), and marker updates to position 1.
4. **Set all digits after marker to '9':** New digits: ['2', '9', '9'], i.e.
"299"
5. **Convert back to int and return:** 299

Here's a modularized C++ code flow for this process, broken down with teaching
comments.
*/
// @lc code=end
