/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us: for a given number n, how many numbers x are there in
 * the range 0 ≤ x < 10^n such that all digits in x are unique? For example, for
 * n=2, we want to count all numbers from 0 to 99 where no digit repeats (e.g.,
 * 11, 22, 33, etc. are not allowed). The challenge is to efficiently count
 * these numbers for any n from 0 to 8.
 *
 * High-Level Summary:
 * ----
 * The solution uses combinatorics to count the number of unique-digit numbers
 * for each possible length (from 1 up to n digits). For each length k (1 ≤ k ≤
 * n), the first digit can be any non-zero digit (except for 0 if k > 1), and
 * each subsequent digit must be different from the previous ones. We multiply
 * the number of choices for each digit position. The total answer is the sum of
 * all such counts for lengths 1 to n, plus 1 for the number 0 (which is always
 * valid). The time complexity is O(n), and space complexity is O(1), since we
 * only use a few variables.
 */

// @lc code=start
class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    // If n is 0, only the number 0 is valid
    if (n == 0)
      return 1;

    int total = 1; // Start with 1 to count the number 0

    // For each possible number of digits (from 1 to n)
    for (int k = 1; k <= n; ++k) {
      // For k = 1, there are 10 choices (0-9)
      if (k == 1) {
        total += 9; // 1-digit numbers: 1-9 (since 0 is already counted)
        continue;
      }

      // For k > 1, calculate the number of unique-digit numbers with k digits
      int count = 9; // The first digit can't be 0, so 9 choices (1-9)
      int available =
          9; // Digits left to choose from (excluding the first digit)

      // For each subsequent digit position, multiply by the number of available
      // digits
      for (int i = 1; i < k; ++i) {
        count *= available;
        --available; // One less digit to choose from for the next position
      }

      total += count; // Add the count for k-digit numbers to the total
    }

    return total;
  }
};
// @lc code=end
