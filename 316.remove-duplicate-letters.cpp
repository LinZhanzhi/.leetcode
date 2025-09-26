/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// Brief, Digested Understanding:
// ----
// The goal is to remove duplicate letters from a string so that every letter
// appears only once, and the resulting string is the smallest possible in
// lexicographical (dictionary) order. This means we want to keep each character
// only once, and if we have a choice, we should pick the character that leads
// to the smallest possible string when reading left to right. We must also
// preserve the relative order of the remaining characters as much as possible
// to achieve the smallest result.

// High-Level Summary:
// ----
// The solution uses a greedy algorithm with a stack to build the answer. We
// keep track of the last occurrence of each character so we know if we can
// safely remove a character and add it later. We also use a set (or boolean
// array) to ensure each character is only added once. For each character, if it
// is not already in the result, we compare it with the top of the stack: if the
// current character is smaller and the character at the top of the stack will
// appear again later, we pop the stack (remove that character from the result).
// This process ensures the result is lexicographically smallest. The time
// complexity is O(N), where N is the length of the string, and space complexity
// is O(1) since the alphabet size is fixed (26).

#include <stack>  // For std::stack
#include <string> // For std::string
#include <vector> // For std::vector

using std::string; // Bring string into scope

// @lc code=start
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // Array to store the last index where each character appears
    std::vector<int> lastIndex(26, -1);
    int n = s.size();

    // Fill lastIndex with the last occurrence of each character
    for (int i = 0; i < n; ++i) {
      lastIndex[s[i] - 'a'] = i;
    }

    // Boolean array to keep track of which characters are in the result
    std::vector<bool> inResult(26, false);

    // Use a stack to build the result string
    std::string result = "";

    for (int i = 0; i < n; ++i) {
      char c = s[i];

      // If character is already in result, skip it
      if (inResult[c - 'a']) {
        continue;
      }

      // While result is not empty, and the last character in result is greater
      // than current character, and the last character will appear again later,
      // we can remove it to get a smaller lex order
      while (!result.empty() && c < result.back() &&
             lastIndex[result.back() - 'a'] > i) {
        // Mark the last character as not in result
        inResult[result.back() - 'a'] = false;
        // Remove the last character
        result.pop_back();
      }

      // Add current character to result and mark it as used
      result.push_back(c);
      inResult[c - 'a'] = true;
    }

    // The result string now contains the answer
    return result;
  }
};
// @lc code=end
