/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using std::sort;
using std::string;
using std::unordered_set;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding the "longest word" in a dictionary (array of
 * strings) that can be assembled by successively building up from smaller
 * prefix-words that are also present in the dictionary, adding one letter at a
 * time at the end of the word. When there are multiple candidates of the same
 * length, we must select the smallest lexicographically (alphabetical order).
 * If no such word exists, we return an empty string.
 */

/*
 * High-Level Summary:
 * ----
 * To solve this, we want to efficiently check, for every word, if all its
 * prefixes (each substring from the start up to one character before its full
 * length) exist in the words list. We do this by:
 *   1. Storing all words in a hash set for quick prefix lookups (O(1) average).
 *   2. Iterating through all words, checking all possible prefixes are present
 * in the set.
 *   3. Keeping track of the best word found (longest, then smallest lex).
 * Sorting the words helps guarantee lexicographical ordering, making
 * tie-breaking easy. This solution is modular, separating prefix-checking into
 * a helper function. Time Complexity: O(N * L), where N is number of words and
 * L is average length (due to prefix checks). Space Complexity: O(N * L) for
 * the hash set.
 */

class Solution {
public:
  // The main function to find the desired longest word
  string longestWord(vector<string> &words) {
    // Helper function: Checks if all prefixes of a word exist in the set
    auto allPrefixesExist = [](const string &word,
                               const unordered_set<string> &wordSet) -> bool {
      // Iterate through prefixes from length 1 to one less than the word's
      // length
      for (size_t l = 1; l < word.length(); ++l) {
        // Check if the prefix [0, l) exists in the set
        if (wordSet.find(word.substr(0, l)) == wordSet.end())
          return false; // If any prefix is missing, return false
      }
      return true; // All prefixes found
    };

    // Sort the words: Longer first, for tie-breakers lex smallest comes first
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      // If lengths differ, longer comes first
      if (a.length() != b.length()) {
        return a.length() > b.length();
      }
      // Otherwise, use lexicographical order
      return a < b;
    });

    // Build a set for O(1) lookups when checking prefixes
    unordered_set<string> wordSet(words.begin(), words.end());

    // Variable to store the best (longest, smallest lexicographically) word
    // found
    string result = "";

    // Since we've sorted longest-then-lex, first valid is the answer
    for (const string &word : words) {
      // Single-letter words are always valid, since empty prefix is considered
      // present
      if (word.length() == 1 || allPrefixesExist(word, wordSet)) {
        result = word;
        break; // Since longer-and-lex smaller sorted first, we can return
               // immediately
      }
    }
    // If no word found, result remains "", as required
    return result;
  }
};
// @lc code=end
