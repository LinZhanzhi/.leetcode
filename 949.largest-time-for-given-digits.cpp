/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */

/*
 * Brief Digested Understanding:
 * ----
 * Given four digits, the task is to arrange them into the latest possible
 * 24-hour time ("HH:MM"), using each digit exactly once. The time must be valid
 * according to the 24-hour clock, which means 'HH' can only be from "00" to
 * "23", and 'MM' from "00" to "59". If no arrangement results in a valid time,
 * we are to return an empty string.
 *
 * In essence, this is a combinatorial problem where we generate all possible
 * permutations of the 4 digits, check which can be a valid time, evaluate them,
 * and pick the one with the highest value.
 */

/*
 * High-Level Summary:
 * ----
 * The solution explores all possible ways to arrange the 4 digits (i.e., all
 * permutations), forming the time as "HH:MM". Each permutation is checked to
 * see if the first two digits ("HH") form a valid hour (00..23) and the last
 * two ("MM") a valid minute (00..59). Valid times are tracked, and the largest
 * found is formatted and returned. If no permutation is valid, return "".
 *
 * Algorithm:
 * - Generate all permutations of the input array (using std::next_permutation)
 * - For each, construct the hour and minute integers
 * - If valid, compare it to the best so far (track max total minutes or as
 * string for lex order)
 * - Build the result in "HH:MM" format, handling leading zeros (e.g., "01:09")
 *
 * Complexity:
 * - Time: O(1) (since there are only 4! = 24 permutations, fast, constant time)
 * - Space: O(1) (apart from minor storage for result and local variables)
 */

#include <algorithm> // For std::sort and std::next_permutation
#include <sstream>   // For std::ostringstream (to build formatted string)
#include <string>    // For std::string (used for the answer)
#include <vector>    // For std::vector<int> (input array)

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the largest valid time
  string largestTimeFromDigits(vector<int> &arr) {
    // Helper function to check if the given hour and minute are valid
    auto isValidTime = [](int h, int m) -> bool {
      // Hours must be between 0 and 23, minutes between 0 and 59
      return (h >= 0) && (h <= 23) && (m >= 0) && (m <= 59);
    };

    // Helper function to format time as "HH:MM" with leading zeroes
    auto formatTime = [](int h, int m) -> string {
      // Use std::ostringstream for zero-padding
      std::ostringstream oss;
      if (h < 10)
        oss << '0';
      oss << h << ':';
      if (m < 10)
        oss << '0';
      oss << m;
      return oss.str();
    };

    // Sort digits to begin with the smallest lexicographical permutation.
    std::sort(arr.begin(), arr.end());

    int maxTime =
        -1; // Store the maximum time in minutes, initialize with -1 (invalid)
    // Will hold the hours and minutes for the largest time found.
    int maxHour = 0, maxMin = 0;

    // Since we only have 4 digits, there are at most 24 permutations.
    do {
      // Construct hours and minutes from the permutation
      int hour = arr[0] * 10 + arr[1];
      int minute = arr[2] * 10 + arr[3];

      // Check if the current arrangement forms a valid time
      if (isValidTime(hour, minute)) {
        int totalMinutes = hour * 60 + minute;
        // If this is the largest time seen so far, update maxTime, maxHour, and
        // maxMin
        if (totalMinutes > maxTime) {
          maxTime = totalMinutes;
          maxHour = hour;
          maxMin = minute;
        }
      }
      // std::next_permutation generates the next lexicographically greater
      // permutation
    } while (std::next_permutation(arr.begin(), arr.end()));

    // If no valid time was found, return the empty string
    if (maxTime == -1) {
      return "";
    }
    // Otherwise, format and return the largest time found
    return formatTime(maxHour, maxMin);
  }
};
// @lc code=end
