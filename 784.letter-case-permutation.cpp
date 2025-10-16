/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// Brief Digested Understanding:
// --------------------------------------
// The core idea here is to generate every string we can create by
// changing each letter in the input string independently to either
// lowercase or uppercase. Digits remain unchanged.
// This means for each letter, we have two possibilities (lower/upper).
// The problem wants us to list all possible permutations that result
// from flipping the case of all letters in any way, and the result
// should be a vector of strings with every such combination.

// High-Level Summary:
// --------------------------------------
// The most straightforward solution is to use backtracking (DFS recursion).
// We traverse the string one character at a time. For each character:
//   - If it's a digit, it can only be itself, so continue.
//   - If it's a letter, explore two branches: one with lowercase,
//     one with uppercase of that character.
// When we reach the end of the string, we add the constructed permutation
// to our answer list. We'll use a helper recursive function for the DFS,
// passing along the current position and the current string being built.
//
// Patterns: Backtracking (DFS), string manipulation.
// Data Structures: Strings, vector for result storage.
// Time Complexity: O(2^L * N) where L = number of letters in s and N =
// s.size(). Space Complexity: O(2^L * N) for result, plus recursion stack up to
// O(N).

#include <cctype> // For std::isalpha, std::tolower, std::toupper
#include <string> // For std::string
#include <vector> // For std::vector

using std::string;
using std::vector;

class Solution {
public:
  // Public function that launches the backtracking process
  vector<string> letterCasePermutation(string s) {
    vector<string> result;
    string current; // Current permutation under construction
    backtrack(s, 0, current, result);
    return result;
  }

private:
  // Helper backtracking function:
  // s: the original input string
  // index: current position we're processing in s
  // current: the permutation built so far
  // result: reference to the answer vector for collecting results
  void backtrack(const string &s, int index, string &current,
                 vector<string> &result) {
    // Base case: if we've processed the entire string, add permutation
    if (index == s.size()) {
      result.push_back(current);
      return;
    }

    char c = s[index];

    if (std::isalpha(c)) {
      // Branch 1: add lowercase version of this letter
      current.push_back(std::tolower(c));
      backtrack(s, index + 1, current, result);
      current.pop_back(); // Remove for other branch

      // Branch 2: add uppercase version of this letter
      current.push_back(std::toupper(c));
      backtrack(s, index + 1, current, result);
      current.pop_back(); // Cleanup for other recursions
    } else {
      // Character is not a letter (likely a digit), just append and move on
      current.push_back(c);
      backtrack(s, index + 1, current, result);
      current.pop_back(); // Remove for other recursive paths
    }
  }
};
// @lc code=end
