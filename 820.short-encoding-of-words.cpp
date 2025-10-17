/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// Brief Digested Understanding:
// ----
// The core of this problem is to find the shortest possible string that can
// encode a list of words such that each word (as a substring between #
// characters) can be uniquely identified. The string is built by concatenating
// all the required words, each followed by a '#' character, in such a way that
// if a word is a suffix of another, we do NOT need to encode it separately.
// That is, only words that are *not* a suffix of any other word must be
// included in the encoding. The main action is "eliminate words that are
// suffixes of others", then total the minimal encoded length.

// High-Level Summary:
// ----
// To solve this efficiently, we first eliminate all words that are suffixes of
// other words, since any such word will already be captured as part of the
// larger word's encoding. The set data structure is helpful for quickly
// removing such words and checking existence. We iterate through each word, and
// for each, remove all possible suffixes (excluding the word itself) from the
// set (since they will be encoded implicitly). Finally, we sum the lengths of
// the remaining words plus one '#' per word for total encoding length.
//
// The main algorithm involves:
//   - Storing all words in a set for O(1) lookup and removal.
//   - For each word, removing all its possible suffixes from the set.
//   - After this process, all remaining words are required in the
//   shortest encoding.
//
// Time complexity: O(N*K^2) where N=number of words and K=max word length
// (since for every word, up to K iterated suffixes are examined). Space
// complexity: O(N*K) to hold all words and their suffixes.

// Include necessary headers for vector, string, and set.
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the minimum length encoding for a list of words.
  int minimumLengthEncoding(vector<string> &words) {
    // Step 1: Place all words into a set for quick lookup and removal.
    unordered_set<string> goodWords(words.begin(), words.end());

    // Step 2: For every word, remove all its suffixes (excluding itself)
    // from the set, as they will be covered by the larger word.
    for (const string &word : words) {
      // Try every possible suffix of the word (not including the whole word
      // itself)
      for (size_t i = 1; i < word.size(); ++i) {
        // Erase the suffix starting at index i (word[i ...])
        goodWords.erase(word.substr(i));
        // This efficiently ensures that only words not covered as suffixes
        // will remain in the set.
      }
    }

    // Step 3: Sum up the lengths of the remaining words plus one ('#') per
    // word.
    int totalLength = 0;
    for (const string &w : goodWords) {
      totalLength += w.size() + 1; // Add 1 for the '#' delimiter
    }

    return totalLength;
  }
};
// @lc code=end
