/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// Brief Digested Understanding:
// ----
// The core of this problem is to find the k-th character in a (potentially
// huge) decoded string, where the string is assembled by reading each
// character: letters are appended as-is, while digits act as repeaters—looping
// the whole tape d times. A direct expansion is impossible due to potentially
// gigantic outputs, so we must "simulate backwards" without materializing the
// full decoded string.
//
// Key constraints are that s contains only lowercase letters/digits, k is
// always within the final decoded length, and direct expansion can be
// infeasible for k up to 1e9 (and actual decoded lengths up to 2^63-1).

// High-Level Summary:
// ----
// We solve this using a two-phase approach. First, we calculate the total
// length of the decoded string by simulating expansion forwards, tracking the
// size at each step without assembling the real string. Once we know the
// overall length, we process s in reverse. For each character, we simulate
// "undoing" the decoding process, updating k to its prior state based on the
// length effects of each digit or letter. If k currently points to an area due
// to repetition, we apply modulo arithmetic to "rewind" k appropriately. When
// we land on a letter and k aligns with that step, that's our answer. This
// keeps the solution linear in the size of s. Time complexity: O(N), Space:
// O(1).

#include <cctype> // Needed for std::isdigit and std::isalpha
#include <string> // Needed for std::string

using std::string;

// @lc code=start
class Solution {
public:
  // Main interface function to find kth character in decoded string
  string decodeAtIndex(string s, int k) {
    // Helper call for Phase 1: compute full decoded length
    long long totalLen = computeDecodedLength(s);

    // Phase 2: process in reverse to find the k-th letter
    return string(1, findKthLetter(s, totalLen, k));
  }

private:
  // Helper function to compute the total length of the decoded string
  long long computeDecodedLength(const string &s) {
    long long size =
        0; // Use long long to prevent overflow for very large strings
    for (char c : s) {
      if (std::isdigit(c)) {
        // If c is a digit, multiply size by digit value
        size *= (c - '0');
      } else {
        // If c is a letter, increase size by 1
        size++;
      }
    }
    return size;
  }

  // Helper function to find the k-th letter by simulating the expansion
  // backwards
  char findKthLetter(const string &s, long long size, int k) {
    // We walk backwards from the end to simulate undoing the encoding steps
    for (int i = s.size() - 1; i >= 0; --i) {
      char c = s[i];
      // Since k is 1-based, map it within current "size"
      k = k % size == 0 ? size : k % size;

      if (std::isdigit(c)) {
        // If a digit, we know the decoded string was size / digit long before
        // expansion
        size /= (c - '0');
        // k remains the same due to covering repetitions
      } else {
        // If a letter and k corresponds to this position, return it
        if (k == size)
          return c;
        // Otherwise, move back one letter
        size--;
      }
    }
    // Control should never reach here as per problem's constraints
    return ' '; // Return space as a fallback, though this should be unreachable
  }
};
/*
 * Sample Trace for Input: s = "leet2code3", k = 10
 *
 * Let's step through how the program works for this particular input.
 *
 * 1. **Phase 1: Compute the Total Decoded Length**
 *    - We parse "leet2code3" character by character to determine how long the
 * fully expanded string would be: l e e t 2 c o d e 3
 *    - Process:
 *      - 'l' → size = 1
 *      - 'e' → size = 2
 *      - 'e' → size = 3
 *      - 't' → size = 4
 *      - '2' → size = 4 * 2 = 8 // string so far is "leetleet"
 *      - 'c' → size = 9
 *      - 'o' → size = 10
 *      - 'd' → size = 11
 *      - 'e' → size = 12
 *      - '3' → size = 12 * 3 = 36 // string so far is
 * "leetleetcodeleetleetcodeleetleetcode"
 *
 *    - **Total decoded length = 36**
 *
 * 2. **Phase 2: Simulate Decoding Backwards to Find the k-th Letter (k=10)**
 *    - We want the 10th letter of the final expanded string.
 *    - We iterate from the end of the encoded string, tracking what value of k
 * corresponds to at each decoding step and shrinking the virtual decoded
 * string.
 *
 *    | i   | char | size(before) | k (current) | Explanation |
 *    |-----|------|--------------|-------------|-------------|
 *    | 9   | '3'  | 36           | 10          | It's a digit. size /= 3 → size
 * = 12. k = 10, so after compression, k = 10 (since 10 <= 12)| | 8   | 'e'  |
 * 12           | 10          | It's a letter. Is k == size? (10 == 12? No)
 * size-- → 11 | | 7   | 'd'  | 11           | 10          | Letter. k == size?
 * (10 == 11? No) size-- → 10     | | 6   | 'o'  | 10           | 10          |
 * Letter. k == size? (10 == 10? Yes)  <--- **We found our letter: 'o'** |
 *
 *    - So, for this input, the answer is 'o'.
 *
 * 3. **Summary Table**
 *    - After decoding, the large string would be:
 *      "leetleetcodeleetleetcodeleetleetcode"
 *    - The 10th character is **'o'**.
 *
 * 4. **Educational Note**
 *    - This method avoids actually constructing the potentially massive decoded
 * string. Instead, we use arithmetic to "reverse" the encoding and map k back
 * to the original character.
 *    - Each step either shrinks the decoded string for a digit (by dividing) or
 * checks if the current letter matches our desired position.
 */
// @lc code=end
