/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks: Given a non-negative integer, you can swap any two digits
 * at most once. What is the largest possible integer you can get by doing this?
 * The key is to find the best two digits to swap (if any) to maximize the
 * number. If the number is already the largest possible, no swap is needed.
 *
 * High-Level Summary:
 * ----
 * The main idea is to scan the digits from left to right, and for each digit,
 * check if there is a larger digit later in the number that can be swapped to
 * the current position to make the number bigger. To do this efficiently, we
 * record the last occurrence of each digit (0-9) in the number. Then, for each
 * digit from left to right, we look for a larger digit (from 9 down to the
 * current digit + 1) that appears later. If found, we swap and return the new
 * number. If no such swap is possible, we return the original number.
 * Time complexity: O(n), where n is the number of digits in num.
 * Space complexity: O(n) for storing the digits and O(1) for the last
 * occurrence array.
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  int maximumSwap(int num) {
    // Convert the number to a string to easily access and swap digits.
    string numStr = std::to_string(num);

    // Store the last occurrence index of each digit (0-9) in the number.
    // This helps us quickly find if a larger digit exists later.
    int last[10] = {0}; // last[d] = last index of digit d in numStr

    // Fill the last occurrence array.
    for (int i = 0; i < numStr.size(); ++i) {
      // numStr[i] - '0' converts the character to its integer value.
      last[numStr[i] - '0'] = i;
    }

    // Traverse the number from left to right.
    for (int i = 0; i < numStr.size(); ++i) {
      int currentDigit = numStr[i] - '0';
      // Try to find a larger digit (from 9 down to currentDigit+1)
      // that occurs later in the number.
      for (int d = 9; d > currentDigit; --d) {
        // If such a digit exists and is after the current position,
        // we can swap to maximize the number.
        if (last[d] > i) {
          // Swap the current digit with the last occurrence of the larger
          // digit.
          std::swap(numStr[i], numStr[last[d]]);
          // After one swap, the number is maximized, so we return.
          return std::stoi(numStr);
        }
      }
      // If no larger digit is found for this position, continue to next.
    }

    // If no swap was made, the number is already the largest possible.
    return num;
  }
};
// @lc code=end
