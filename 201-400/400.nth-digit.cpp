/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the nth digit in a sequence formed by
 * concatenating all positive integers together (i.e., "123456789101112...").
 * For example, the 11th digit in this sequence is '0', which is the second
 * digit of the number 10. The challenge is to efficiently determine which
 * number and which digit within that number corresponds to the nth position,
 * especially for large n.
 */

/*
 * High-Level Summary:
 * ----
 * The solution works by:
 *   1. Determining the length of the numbers (1-digit, 2-digit, etc.) that
 * contain the nth digit.
 *   2. Calculating the exact number in that range where the nth digit falls.
 *   3. Extracting the specific digit from that number.
 *
 * Algorithmic Steps:
 *   - For each group of numbers with the same digit length, calculate how many
 * digits they contribute.
 *   - Subtract these counts from n until we find the group containing the nth
 * digit.
 *   - Compute the actual number and the digit's position within it.
 *
 * Time Complexity: O(log n), since the number of digit-length groups is
 * logarithmic in n. Space Complexity: O(1), as only a few variables are used.
 */

// @lc code=start
class Solution {
public:
  int findNthDigit(int n) {
    // Step 1: Determine the digit length of the number containing the nth
    // digit.
    long long digitLength = 1; // Start with 1-digit numbers
    long long count = 9;       // There are 9 one-digit numbers (1-9)
    long long start = 1;       // The first number with digitLength digits

    // Loop to find the correct digit length group
    // For each group, check if n is within the total digits contributed by that
    // group
    while (n > digitLength * count) {
      n -= digitLength * count; // Remove all digits from this group
      digitLength++; // Move to the next group (2-digit, 3-digit, etc.)
      count *= 10;   // There are 90 two-digit numbers, 900 three-digit, etc.
      start *= 10;   // The first number in the next group (10, 100, etc.)
    }

    // Step 2: Find the actual number that contains the nth digit
    // (n-1) because we want zero-based index within the group
    long long number = start + (n - 1) / digitLength;

    // Step 3: Find the digit within the number
    // The position of the digit in the number (0-based)
    int digitIndex = (n - 1) % digitLength;

    // Convert the number to string to easily access the digit
    std::string numberStr = std::to_string(number);

    // Return the digit as an integer
    return numberStr[digitIndex] - '0';
  }
};
// @lc code=end
