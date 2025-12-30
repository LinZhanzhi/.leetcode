/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is to decode a string that uses a specific encoding pattern: a
 * number k followed by a substring in square brackets, like
 * "k[encoded_string]". This means the substring inside the brackets should be
 * repeated k times. The encoding can be nested, so we need to handle cases
 * where brackets appear inside other brackets. The goal is to process the
 * string and return its fully decoded version.
 *
 * High-Level Summary:
 * ----
 * The solution uses a stack-based approach to handle nested encodings. As we
 * scan the string, we keep track of numbers (for repeat counts) and substrings.
 * When we see a '[', we push the current substring and repeat count onto stacks
 * and start a new substring. When we see a ']', we pop the last repeat count
 * and substring, repeat the current substring accordingly, and append it to the
 * previous substring. This approach efficiently handles nested and sequential
 * encodings. The time complexity is O(N), where N is the length of the string,
 * since each character is processed once. The space complexity is also O(N) due
 * to the use of stacks.
 */

#include <cctype> // For std::isdigit
#include <stack>  // For std::stack
#include <string> // For std::string

using std::stack;
using std::string;

// @lc code=start
class Solution {
public:
  // Decodes the encoded string according to the k[encoded_string] rule.
  string decodeString(string s) {
    stack<int> countStack; // Stack to store repeat counts for nested encodings
    stack<string>
        stringStack; // Stack to store previous substrings for nested encodings
    string current;  // Current substring being built
    int k = 0;       // Current repeat count being built

    // Iterate through each character in the input string
    for (char ch : s) {
      if (std::isdigit(ch)) {
        // If the character is a digit, build the repeat count (could be more
        // than one digit)
        k = k * 10 + (ch - '0');
      } else if (ch == '[') {
        // When we see '[', push the current repeat count and substring onto
        // their stacks
        countStack.push(k);
        stringStack.push(current);
        // Reset current substring and repeat count for the new context
        current = "";
        k = 0;
      } else if (ch == ']') {
        // When we see ']', pop the last repeat count and substring
        int repeatTimes = countStack.top();
        countStack.pop();
        string prev = stringStack.top();
        stringStack.pop();
        // Repeat the current substring and append to the previous substring
        for (int i = 0; i < repeatTimes; ++i) {
          prev += current;
        }
        // Set current to the combined string for further processing
        current = prev;
      } else {
        // If it's a letter, just add it to the current substring
        current += ch;
      }
    }
    // After processing all characters, current holds the fully decoded string
    return current;
  }
};
// @lc code=end
