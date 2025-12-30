/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start

#include <string> // For std::string, std::stoi, etc.
#include <vector> // For std::vector

using std::string;
using std::vector;

/**
 * Brief Digested Understanding:
 * ----
 * The problem gives a coordinate string with all commas, spaces, and decimal
 * points removed, and asks us to reconstruct every possible pair of numbers
 * (split from the inner digits), inserting decimal points in any valid way,
 * such that neither X nor Y contains invalid formats (like leading zeros except
 * "0", trailing zeros after decimal points, or redundant representations). All
 * outputs must have the format "(X, Y)" with a single space after the comma,
 * and every X and Y must be a valid original number as described.
 *
 * High-Level Summary:
 * ----
 * The key idea is to split the given inner substring (all digits, without
 * parentheses) at every possible position into a left and a right part
 * (corresponding to X and Y). For each split, we generate all valid numeric
 * representations for each part by possibly inserting a single decimal point,
 * while ensuring that numbers do not start with unnecessary leading zeroes or
 * end with unnecessary trailing zeroes after the decimal point. We use helper
 * functions to generate all valid numbers for a substring. Finally, for every
 * valid combination of (X, Y), we join them into the final output format. Time
 * complexity is O(N^3), where N is the maximum length of the input string,
 * acceptable for the constraints.
 */

// Helper function to generate all valid representations of a numeric string
// with or without a decimal point. Returns all possible valid forms.
vector<string> generateValidNumbers(const string &s) {
  vector<string> results;

  int n = s.size();

  // If the string is a single digit, it's always valid (e.g. "0", "5")
  if (n == 1) {
    results.push_back(s);
    return results;
  }

  // If it starts and ends with '0', but is not "0" itself, invalid (e.g. "00",
  // "000")
  if (s[0] == '0' && s[n - 1] == '0') {
    return {}; // No valid representation
  }

  // If it starts with zero, it can only be "0.xxx" (no integer part longer than
  // 1)
  if (s[0] == '0') {
    // Insert decimal after the first digit, if there's more than one digit
    results.push_back("0." + s.substr(1));
    return results; // Cannot have "00...x" or "01"
  }

  // If it ends with zero, it can only be integer - decimals like "1230.45" are
  // not allowed
  if (s[n - 1] == '0') {
    results.push_back(s); // Only the integer form is valid
    return results;
  }

  // Otherwise, both integer and decimal forms are allowed
  results.push_back(s); // Add integer form without decimal

  // Try every position to insert a decimal point (except at the ends)
  for (int i = 1; i < n; ++i) {
    // Insert decimal after position i-1
    string num = s.substr(0, i) + "." + s.substr(i);
    results.push_back(num);
  }
  return results;
}

// Main solution class
class Solution {
public:
  vector<string> ambiguousCoordinates(string s) {
    vector<string> results;

    // Remove the parentheses
    string digits = s.substr(1, s.size() - 2);

    // Split at each possible position (at least one digit on each side)
    for (int i = 1; i < digits.size(); ++i) {
      string left = digits.substr(0, i);
      string right = digits.substr(i);

      // Generate all valid forms for both sides
      vector<string> leftParts = generateValidNumbers(left);
      vector<string> rightParts = generateValidNumbers(right);

      // For each valid left and right, combine into final coordinate
      for (const string &l : leftParts) {
        for (const string &r : rightParts) {
          results.push_back("(" + l + ", " + r + ")");
        }
      }
    }
    return results;
  }
};
// @lc code=end
