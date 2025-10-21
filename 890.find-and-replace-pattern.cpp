/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// Brief Digested Understanding:
// -----
// This problem asks us to find all words from a list that match a given pattern
// in a special way: A word "matches" the pattern if we can relabel (permute)
// the letters of the pattern one-to-one (a bijection: both injective and
// surjective) to get the word. For instance, "mee" matches "abb", because "a"
// can map to "m", and both "b"s (the remaining two letters in the pattern) map
// to "e". Each letter must map to only one letter, and each letter in the word
// can come from only one letter in the pattern (no two different letters in the
// pattern map to the same letter in the word). The main challenge is to test
// this bijective mapping for every word and the pattern.

// High-Level Summary:
// -----
// The core idea is to check, for each word, whether we can set up a bijective
// (one-to-one and onto) mapping between the letters of the pattern and the
// letters of the word. We'll do this by:
//   1. Writing a helper function to check if two strings (a word and the
//   pattern) have such a
//      letter-by-letter bijection.
//   2. For each word in the input, use this function to filter out matching
//   words.
// We'll use fixed-size arrays or hash maps to record both the mapping from
// pattern->word letters and from word->pattern letters, ensuring the mapping is
// unique both directions. Time complexity is O(N*M), where N = number of words,
// M = pattern length (since comparing each word with the pattern is O(M)).
// Space complexity is also modest: O(M) extra per call for mappings.

// Be prepared to explain in comments why a single-direction mapping isn't
// enough (must check both ways). This teaches the bijection concept typically
// seen in isomorphism problems.

#include <string>        // For std::string
#include <unordered_map> // For mapping characters
#include <vector>        // For std::vector

using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Public entry point: given list of words and a pattern, return matching
  // words
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> result; // To store all words matching the pattern

    // Loop through each word in the input list
    for (const string &word : words) {
      // Check if the current word matches the pattern using the isMatch helper
      if (isMatch(word, pattern)) {
        result.push_back(word); // Add it to our list of matching words
      }
    }

    return result; // Return all found matches
  }

private:
  // Helper function to check bijective correspondence (bijective mapping)
  // between word and pattern Returns true if a bijection (one-to-one & onto
  // mapping) is possible
  bool isMatch(const string &word, const string &pattern) {
    // If lengths differ, the mapping is impossible
    if (word.length() != pattern.length())
      return false;

    // These hash maps will store the mapping from pattern character -> word
    // character and word character -> pattern character, respectively.
    unordered_map<char, char>
        patToWord; // pattern character maps to word character
    unordered_map<char, char>
        wordToPat; // word character maps to pattern character

    for (int i = 0; i < pattern.length(); ++i) {
      char p = pattern[i];
      char w = word[i];

      // If we've already mapped 'p', ensure it maps to 'w'
      if (patToWord.count(p)) {
        if (patToWord[p] != w)
          return false; // Mapping is inconsistent
      } else {
        patToWord[p] = w; // Assign new mapping from pattern to word letter
      }

      // Similarly, check the reverse direction to guarantee one-to-one
      // (bijective) mapping
      if (wordToPat.count(w)) {
        if (wordToPat[w] != p)
          return false; // Two pattern letters map to the same word letter (not
                        // allowed)
      } else {
        wordToPat[w] = p; // Assign new reverse mapping
      }
    }
    // If we finish without violations, the mapping is bijective
    return true;
  }
};
// @lc code=end
