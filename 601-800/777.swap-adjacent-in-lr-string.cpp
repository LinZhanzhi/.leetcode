/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start

#include <string>  // Include for using std::string
using std::string; // Use std::string without qualifying every time

/*
 * Brief Digested Understanding:
 * --------------------------------
 * This problem asks: Can you turn the string `start` into `result` by making a
 * series of specific allowed swaps? You can only swap "XL" into "LX" (so 'L'
 * moves left past an 'X'), or "RX" into "XR" (so 'R' moves right past an 'X').
 * You cannot reorder 'L' and 'R' themselves, nor can these move past each other
 * or swap with each other. 'L' can only move left, and 'R' only right. All
 * strings are the same length and consist only of 'L', 'R', and 'X'.
 *
 * Key is understanding that swaps only let L drift left, R drift right,
 * never cross each other, and counts of L/R must match.
 *
 * High-Level Summary:
 * --------------------------------
 * Solution approach:
 *   1. First, strip out all 'X's from both start and result; if the character
 * order of L and R does not match, return false. This checks if the two strings
 * are 'structurally' compatible.
 *   2. Then, scan both strings, and for every 'L' and 'R', check that their
 * positions obey the allowed movement rules: L cannot move right, R cannot move
 * left. That is, for 'L': position in start >= position in result. for 'R':
 * position in start <= position in result.
 *   3. If all these checks pass, the transformation can be done. Each step is
 * O(n) time, O(n) space.
 *   4. Helper functions will be used to keep matching indices modularized and
 * logic clearly separated.
 */

class Solution {
public:
  // Main function to determine if start can be transformed into result
  bool canTransform(string start, string result) {
    // Step 1: Quick check – if the non-X ordering does not match, impossible
    if (!sameNonXOrder(start, result))
      return false;

    // Step 2: Check if 'L' obeys the allowed movement rules
    if (!checkLPositions(start, result))
      return false;

    // Step 3: Check if 'R' obeys the allowed movement rules
    if (!checkRPositions(start, result))
      return false;

    // If both checks passed, it is possible
    return true;
  }

private:
  // Helper to return true if, after removing X's, the remaining string orders
  // are the same
  bool sameNonXOrder(const string &s1, const string &s2) {
    string a, b;
    for (char c : s1) {
      if (c != 'X')
        a.push_back(c);
    }
    for (char c : s2) {
      if (c != 'X')
        b.push_back(c);
    }
    // They must have the same L/R order for a valid transformation
    return a == b;
  }

  // Helper for 'L': Each 'L' in result must not move right compared to start
  bool checkLPositions(const string &start, const string &result) {
    // Indices to track 'L' characters in both strings
    int n = start.size();
    int i = 0, j = 0;
    // Iterate over both strings, only when finding an 'L'
    while (i < n && j < n) {
      // Advance i to next 'L' in start
      while (i < n && start[i] != 'L')
        ++i;
      // Advance j to next 'L' in result
      while (j < n && result[j] != 'L')
        ++j;
      // If one runs out before the other, we've already failed the non-X order
      // test
      if (i < n && j < n) {
        // 'L' can only move to the left (i >= j)
        if (i < j) {
          return false;
        }
        ++i;
        ++j;
      }
    }
    return true;
  }

  // Helper for 'R': Each 'R' in start must not move left compared to result
  bool checkRPositions(const string &start, const string &result) {
    int n = start.size();
    int i = 0, j = 0;
    while (i < n && j < n) {
      // Advance i to next 'R' in start
      while (i < n && start[i] != 'R')
        ++i;
      // Advance j to next 'R' in result
      while (j < n && result[j] != 'R')
        ++j;
      // If one runs out before the other, we've already failed the non-X order
      // test
      if (i < n && j < n) {
        // 'R' can only move to the right (i <= j)
        if (i > j) {
          return false;
        }
        ++i;
        ++j;
      }
    }
    return true;
  }
};

// @lc code=end
