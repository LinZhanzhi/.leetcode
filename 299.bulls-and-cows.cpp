/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to compare two strings, `secret` and `guess`, both representing
 * numbers, and count:
 *   - "Bulls": digits that are the same and in the same position in both
 * strings.
 *   - "Cows": digits that are present in both strings but in different
 * positions (excluding those already counted as bulls). The result should be
 * formatted as "xAyB", where x is the number of bulls and y is the number of
 * cows. We must handle duplicate digits carefully so that each digit is only
 * counted once as a cow or bull.
 *
 * High-Level Summary:
 * ----
 * The solution iterates through both strings simultaneously:
 *   - First, it counts bulls by comparing characters at the same index.
 *   - For non-bull positions, it records the frequency of each digit in both
 * `secret` and `guess`.
 *   - Then, for each digit (0-9), it adds the minimum count from both `secret`
 * and `guess` to the cow count (since only the overlapping unmatched digits can
 * be cows).
 *   - The final answer is constructed as "bullsA" + "cowsB".
 * Time Complexity: O(n), where n is the length of the strings.
 * Space Complexity: O(1), since the digit counts are fixed at 10 (for digits
 * 0-9).
 */

#include <algorithm> // Include for std::min
#include <string>    // Include for std::string
#include <vector>    // Include for std::vector

using std::min;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // This function returns the hint string in the format "xAyB"
  string getHint(string secret, string guess) {
    int bulls = 0; // Counter for bulls (correct digit and position)
    int cows = 0;  // Counter for cows (correct digit, wrong position)
    // Arrays to count the frequency of each digit (0-9) in unmatched positions
    vector<int> secret_count(10, 0); // secret_count[d] = number of times digit
                                     // d appears in secret (excluding bulls)
    vector<int> guess_count(10, 0);  // guess_count[d] = number of times digit d
                                     // appears in guess (excluding bulls)

    // First pass: count bulls and record unmatched digits
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        // If the digit matches in both value and position, it's a bull
        ++bulls;
      } else {
        // Otherwise, record the digit for possible cow matching
        // Convert char digit to int by subtracting '0'
        ++secret_count[secret[i] - '0'];
        ++guess_count[guess[i] - '0'];
      }
    }

    // Second pass: count cows by finding the minimum overlap of unmatched
    // digits
    for (int d = 0; d < 10; ++d) {
      // For each digit, the number of cows is the minimum of its unmatched
      // count in secret and guess
      cows += min(secret_count[d], guess_count[d]);
    }

    // Construct the result string in the required format
    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }
};
// @lc code=end
