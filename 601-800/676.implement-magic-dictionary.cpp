/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is to design a data structure that, after being
 * initialized with a list of unique words, can efficiently check if a given
 * word can be transformed into any word in the dictionary by changing exactly
 * one character (no more, no less). The check must ensure that only one
 * character is changed, and the resulting word must exist in the original
 * dictionary.
 *
 * High-Level Summary:
 * ----
 * We'll store the dictionary words in a hash set for fast lookup. For the
 * search operation, for each character position in the search word, we'll try
 * replacing it with every other lowercase letter and check if the resulting
 * word exists in the dictionary (and is not the same as the original word).
 * This brute-force approach is efficient enough given the problem's constraints
 * (word and dictionary sizes are small). The main data structure is an
 * unordered_set<string> for O(1) lookups. Time complexity for search is
 * O(L*26), where L is the word length, and space is O(N*L) for N words.
 */

#include <string>        // For std::string
#include <unordered_set> // For std::unordered_set
#include <vector>        // For std::vector

using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class MagicDictionary {
private:
  // Store all dictionary words for fast lookup
  unordered_set<string> dict;

  // Helper function: Checks if two words differ by exactly one character
  bool differByOne(const string &word1, const string &word2) {
    // If lengths differ, they can't be transformed by changing one char
    if (word1.length() != word2.length())
      return false;
    int diffCount = 0;
    // Compare each character
    for (size_t i = 0; i < word1.length(); ++i) {
      if (word1[i] != word2[i]) {
        ++diffCount;
        // If more than one difference, return false early
        if (diffCount > 1)
          return false;
      }
    }
    // Return true only if exactly one character is different
    return diffCount == 1;
  }

public:
  // Constructor: Initializes the dictionary as empty
  MagicDictionary() {
    // No initialization needed; dict is empty by default
  }

  // Builds the dictionary from a list of words
  void buildDict(vector<string> dictionary) {
    // Insert all words into the unordered_set for O(1) lookup
    for (const string &word : dictionary) {
      dict.insert(word);
    }
  }

  // Returns true if searchWord can be transformed into a dictionary word
  // by changing exactly one character
  bool search(string searchWord) {
    // For each position in the word
    for (size_t i = 0; i < searchWord.length(); ++i) {
      char originalChar = searchWord[i];
      // Try replacing with every other lowercase letter
      for (char c = 'a'; c <= 'z'; ++c) {
        // Skip if the character is the same as original
        if (c == originalChar)
          continue;
        // Replace the character at position i
        searchWord[i] = c;
        // Check if the modified word exists in the dictionary
        if (dict.count(searchWord)) {
          // Found a valid transformation; return true
          return true;
        }
      }
      // Restore the original character before next iteration
      searchWord[i] = originalChar;
    }
    // No valid transformation found; return false
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end
