/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// Brief Digested Understanding:
// ----
// The essence of this problem is to count how many words from a given list are
// subsequences of a target string `s`. A subsequence is formed by deleting zero
// or more characters from `s` without changing the order of the remaining
// characters. The twist is that `s` can be large (up to 50,000 characters),
// while there can be many (up to 5,000) candidate words, each up to 50 letters
// long. Brute-forcing each check naively would be too slow for the largest
// constraints, so our job is to efficiently determine subsequence membership
// for all words, ideally leveraging fast lookups and shared computation where
// possible. The challenge is in checking each word efficiently and avoiding
// redundant work.

// High-Level Summary:
// ----
// To efficiently check for subsequences, we preprocess string `s` by creating
// an index of positions for each character ('a'-'z'). For each word, we try to
// match its letters in order to positions in `s` moving forward—each time, we
// use binary search to find the valid next position after the previous match.
// This makes the per-word check logarithmic in the size of `s`, i.e., O(L log
// N), where N is length of `s` and L is the length of the word (max 50). This
// approach is much faster than comparing each word directly with `s` from
// scratch. All logic is modularized into clearly-named helper functions for
// preprocessing and matching. The overall time complexity is O(N + W * L * log
// N) with N=size of `s`, W=number of words, L=max word length, and space O(N +
// W * L). This is manageable for the given constraints.

// Required #includes for string and vector usage
#include <algorithm> // for std::lower_bound
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function: returns the number of words in `words` that are subsequences
  // of `s`
  int numMatchingSubseq(string s, vector<string> &words) {
    // Step 1: Preprocess `s` to store for each character all its positions
    // (indices) in `s`
    auto charIndices = preprocessCharIndices(s);

    int count = 0; // This will keep track of words that are valid subsequences
    // Step 2: For each word, check if it is a subsequence of `s` using the
    // preprocessed data
    for (const string &word : words) {
      if (isSubsequence(word, charIndices)) {
        ++count; // If word is a subsequence, increment the counter
      }
    }
    return count;
  }

private:
  // Helper function to build mapping from each character to all its indices in
  // `s` The result is a vector of 26 vectors (for each lowercase letter)
  vector<vector<int>> preprocessCharIndices(const string &s) {
    // 26 lowercase English letters
    vector<vector<int>> indices(26);
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      char c = s[i];
      indices[c - 'a'].push_back(i);
      // indices[c - 'a'] holds all positions of letter c in `s`
    }
    return indices;
  }

  // Helper function to determine if the given word is a subsequence of `s`
  // as represented by the preprocessed `charIndices`.
  bool isSubsequence(const string &word,
                     const vector<vector<int>> &charIndices) {
    int prevPos = -1; // Start searching from before the beginning of `s`
    // For each character in the word, we look for a match AFTER prevPos
    for (char c : word) {
      const vector<int> &positions = charIndices[c - 'a'];
      if (positions.empty()) {
        // Character c does not appear in `s` at all—word can't be a subsequence
        return false;
      }
      // Use binary search to find the first occurrence > prevPos
      auto it =
          std::lower_bound(positions.begin(), positions.end(), prevPos + 1);
      if (it == positions.end()) {
        // No occurrence of c after prevPos, sequence cannot be formed
        return false;
      }
      prevPos = *it; // Move to that occurrence for next search
    }
    // All characters were found in order
    return true;
  }
};
// @lc code=end
