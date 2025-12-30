/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// Brief Digested Understanding:
// ----
// This problem asks us to find all words from the first list (words1) such that
// every word from the second list (words2) is a subset of those words. In plain
// terms, we're looking for the words in words1 that "cover" (contain at least
// the required count of every letter) all words in words2 simultaneously. For
// each letter, if any word in words2 needs 'k' of that letter, the candidate
// from words1 must have at least that many.
//
// The main challenge is to efficiently process potentially thousands of words,
// each up to 10 characters, in a way that scales well.

// High-Level Summary:
// ----
// The efficient solution leverages a frequency-count merging idea: We first
// compute a max frequency count for each letter, considering all words in
// words2. This "merged count" represents the tightest letter constraints any
// universal word must satisfy. Then, for each word in words1, we count its
// letters and check whether it meets or exceeds every required letter count.
//      - We use fixed-size (26 element) arrays to represent letter counts.
//      - Processing words2 for the requirement is O(words2.length *
//      word2.length).
//      - Checking each word in words1 is O(words1.length * word1.length).
// Expected overall time complexity is O(words1.length * L1 + words2.length *
// L2), with L1 and L2 being the max word lengths (~10). Space complexity is O(N
// + M), dominated by input size and fixed count arrays.

#include <algorithm> // For std::max used in merging frequency counts.
#include <string>    // To use std::string for the word manipulations.
#include <vector>    // To use std::vector for the output and inputs.

using std::max;
using std::string;
using std::vector;

class Solution {
public:
  // Helper function that counts the frequency of each lowercase letter in a
  // string. Returns a vector of 26 integers representing counts for 'a' to 'z'.
  vector<int> countLetters(const string &word) {
    vector<int> count(26, 0); // 26 slots for 'a' to 'z'
    for (char c : word) {
      count[c - 'a']++; // Increment the count for letter c
    }
    return count; // Return the frequency array
  }

  // Main function to find universal words.
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    // Step 1: Compute the merged maximal requirement for each letter
    vector<int> required(26,
                         0); // Stores the max required count for each letter

    // For every word in words2, update the required count for each letter
    for (const string &b : words2) {
      vector<int> bCount = countLetters(b); // Count letters in current b
      // For every letter, keep the maximum of previously seen and just found
      // frequencies
      for (int i = 0; i < 26; ++i) {
        required[i] = max(required[i], bCount[i]);
      }
    }

    vector<string> result; // This will store all universal words

    // Step 2: For each word in words1, check if it covers the requirement
    for (const string &a : words1) {
      vector<int> aCount = countLetters(a); // Count letters in word a
      bool universal = true;                // Assume it's universal

      // Check requirement: for every letter, does a have enough?
      for (int i = 0; i < 26; ++i) {
        if (aCount[i] < required[i]) {
          // If any letter is under-represented, a is not universal
          universal = false;
          break;
        }
      }
      // If word a satisfies all letter frequency requirements, add to result
      if (universal) {
        result.push_back(a);
      }
    }
    // Return the final list of universal words
    return result;
  }
};
// @lc code=end
