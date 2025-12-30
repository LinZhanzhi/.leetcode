/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to remove exactly k digits from a given number (as a
 * string) so that the resulting number is as small as possible. We must
 * preserve the order of the remaining digits, and the result should not have
 * leading zeros (unless the answer is "0"). The challenge is to decide which
 * digits to remove to achieve the smallest possible number.
 */

/*
 * High-Level Summary:
 * ----
 * The optimal approach is to use a greedy algorithm with a stack (or string as
 * a stack). We iterate through each digit in the input string. For each digit,
 * we remove the previous digit from the stack if it is larger than the current
 * digit and if we still have digits left to remove (k > 0). This ensures that
 * larger digits are removed from the left, making the number smaller. After
 * processing all digits, if we still have digits to remove (k > 0), we remove
 * them from the end. Finally, we remove any leading zeros from the result.
 *
 * Time Complexity: O(N), where N is the length of num (each digit is pushed and
 * popped at most once). Space Complexity: O(N), for the stack to store the
 * digits.
 */

#include <string>  // For std::string
using std::string; // Bring string into the current namespace

// @lc code=start
class Solution {
public:
  string removeKdigits(string num, int k) {
    // This string will be used as a stack to build the smallest number
    string stack;

    // Iterate through each digit in the input number
    for (char digit : num) {
      // While the stack is not empty, the last digit in the stack is greater
      // than the current digit, and we still have digits to remove (k > 0), pop
      // the last digit from the stack. This is the greedy step: remove larger
      // digits from the left to make the number smaller.
      while (!stack.empty() && k > 0 && stack.back() > digit) {
        stack.pop_back();
        k--; // Decrement the number of digits we need to remove
      }
      // Push the current digit onto the stack
      stack.push_back(digit);
    }

    // If there are still digits to remove after the loop,
    // remove them from the end of the stack (rightmost digits)
    while (k > 0 && !stack.empty()) {
      stack.pop_back();
      k--;
    }

    // Remove leading zeros from the result
    int start = 0;
    while (start < stack.size() && stack[start] == '0') {
      start++;
    }

    // If all digits are removed or only zeros remain, return "0"
    if (start == stack.size()) {
      return "0";
    }

    // Return the substring from the first non-zero digit to the end
    return stack.substr(start);
  }
};
// @lc code=end
