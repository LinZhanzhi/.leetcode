/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a string that is a jumbled collection of English letters, which
 * together represent the names of digits (from "zero" to "nine") in any order
 * and possibly repeated. Our task is to figure out which digits (0-9) are
 * present, how many times each appears, and return a string of those digits in
 * ascending order. The key is to "decode" the string by identifying unique
 * clues in the letter frequencies that correspond to each digit.
 *
 * High-Level Summary:
 * ----
 * The solution uses the fact that certain letters appear in only one digit's
 * English name. For example, 'z' only appears in "zero", 'w' only in "two", 'u'
 * only in "four", etc. We count the frequency of each letter in the input,
 * then, in a specific order, deduce the count of each digit by looking for
 * these unique letters. After accounting for those, we use the remaining
 * letters to deduce the rest of the digits. The algorithm is O(N) time and O(1)
 * space (since the alphabet and digit set are constant).
 */

#include <string>
#include <vector>
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  string originalDigits(string s) {
    // Array to count the frequency of each letter in the input string.
    // There are 26 lowercase English letters.
    int letterCount[26] = {0};
    for (char c : s) {
      letterCount[c - 'a']++;
    }

    // Array to store the count of each digit (0-9).
    int digitCount[10] = {0};

    // The order of deduction is important.
    // We start with digits that have unique identifying letters.
    // 0: 'z' in "zero"
    digitCount[0] = letterCount['z' - 'a'];
    // 2: 'w' in "two"
    digitCount[2] = letterCount['w' - 'a'];
    // 4: 'u' in "four"
    digitCount[4] = letterCount['u' - 'a'];
    // 6: 'x' in "six"
    digitCount[6] = letterCount['x' - 'a'];
    // 8: 'g' in "eight"
    digitCount[8] = letterCount['g' - 'a'];

    // Now, deduce digits whose unique letters are no longer unique after above
    // are removed. 3: 'h' in "three" (but also in "eight")
    digitCount[3] = letterCount['h' - 'a'] - digitCount[8];
    // 5: 'f' in "five" (but also in "four")
    digitCount[5] = letterCount['f' - 'a'] - digitCount[4];
    // 7: 's' in "seven" (but also in "six")
    digitCount[7] = letterCount['s' - 'a'] - digitCount[6];

    // 1: 'o' in "one" (but also in "zero", "two", "four")
    digitCount[1] =
        letterCount['o' - 'a'] - digitCount[0] - digitCount[2] - digitCount[4];

    // 9: 'i' in "nine" (but also in "five", "six", "eight")
    digitCount[9] =
        letterCount['i' - 'a'] - digitCount[5] - digitCount[6] - digitCount[8];

    // Build the output string by appending each digit the number of times it
    // appears.
    string result;
    for (int digit = 0; digit <= 9; ++digit) {
      // Append the digit as a character, digitCount[digit] times.
      result.append(digitCount[digit], '0' + digit);
    }
    return result;
  }
};
// @lc code=end
