/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks us to count how many numbers between 1 and n (inclusive)
 * can be "rotated" digit-by-digit (each digit rotated 180 degrees), so that:
 *  - Each digit still forms a valid digit after rotation (only 0, 1, 2, 5, 6,
 * 8, 9 are valid).
 *  - The number changes to a different number after full rotation (it can't
 * stay the same). The key is recognizing that some digits (3, 4, 7) are invalid
 * after rotation, and that for a number to be "good", it must use at least one
 * digit that is "changed" during rotation (2 <-> 5, 6 <-> 9). If a number only
 * contains non-changing digits (0, 1, 8), it is NOT good even if it remains
 * valid. The heart of the problem is thus about validating the mapping of each
 * digit and ensuring at least one is of the "change" type (2, 5, 6, 9).
 *
 * High-Level Summary:
 * ----
 * We'll solve this problem using a simple iteration from 1 to n. For each
 * number:
 *   - We'll check if every digit is valid (doesn't contain 3, 4, 7).
 *   - We'll also check if it contains at least one "change" digit (2, 5, 6, 9).
 * To keep the code modular and beginner-friendly, we'll create helper
 * functions:
 *   - One to tell if a single digit is valid,
 *   - Another to check if a digit causes the number to change,
 *   - And one to check if an integer is a "good" number using the above checks.
 * We simply count up all such "good" numbers. This brute-force approach is
 * efficient enough because n is at most 10,000. Both time and space complexity
 * are O(n).
 */

// @lc code=start
class Solution {
public:
  // Helper function: Returns true if digit is valid when rotated (not 3,4,7)
  bool isValidDigit(int digit) {
    // Digits 0, 1, 2, 5, 6, 8, 9 are valid; 3,4,7 are invalid
    // We use a lookup table for clarity and speed
    static bool validTable[10] = {true, true, true,  false, false,
                                  true, true, false, true,  true};
    return validTable[digit];
  }

  // Helper function: Returns true if digit changes when rotated (2,5,6,9)
  bool isChangedDigit(int digit) {
    // Only 2, 5, 6, 9 become different digits after rotation
    return digit == 2 || digit == 5 || digit == 6 || digit == 9;
  }

  // Helper function: Determines if a number is a "good" number
  bool isGoodNumber(int num) {
    bool hasChanged = false; // Flag: have we seen any changing digit?
    int original = num;      // For possible advanced usages or debugging

    // Examine each digit of the number
    while (num > 0) {
      int digit = num % 10; // Extract the last digit

      // If we hit an invalid digit (3, 4, 7), the number is invalid
      if (!isValidDigit(digit))
        return false;

      // If current digit changes upon rotation, mark it
      if (isChangedDigit(digit))
        hasChanged = true;

      num /= 10; // Remove the last digit and continue
    }

    // Only return true if at least one digit would change
    return hasChanged;
  }

  int rotatedDigits(int n) {
    int goodCount = 0; // Counter for good numbers

    // Check every number from 1 up to n
    for (int i = 1; i <= n; ++i) {
      // If this is a "good" number, increment our count
      if (isGoodNumber(i)) {
        ++goodCount;
      }
    }

    // After checking all numbers, return the final count
    return goodCount;
  }
};
// @lc code=end
